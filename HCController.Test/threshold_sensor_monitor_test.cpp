#include <iostream>
#include "pch.h"
#include "gtest/gtest.h"
#include "threshold_sensor_monitor.h"
#include "monitor_threshold_type.h"
#include "monitor_trigger_type.h"
#include "base_monitor_actuator.h"

class ThresholdSensorMonitorActuator :public BaseMonitorActuator {
private:
	int callbackCallCounter;

public:
	ThresholdSensorMonitorActuator() : callbackCallCounter(0) {	}

	virtual void triggerActuator() {
		std::cerr << "trigger called" << std::endl;

		callbackCallCounter++;
	}

	int getCallCounter() {
		return callbackCallCounter;
	}
};

TEST(ThresholdSensorMonitor, MonitorInitialization) {
	BaseMonitorActuator* actuator = new ThresholdSensorMonitorActuator;
	ThresholdSensorMonitor monitor(15, MonitorThresholdType::GreaterThan, actuator);

	int thresholdValue = monitor.getThresholdValue();

	EXPECT_EQ(thresholdValue, 15);
}

TEST(ThresholdSensorMonitor, AllwaysTriggerMonitorGreaterThanThreshold) {
	ThresholdSensorMonitorActuator* actuator = new ThresholdSensorMonitorActuator;
	ThresholdSensorMonitor monitor(15, MonitorThresholdType::GreaterThan, actuator);

	EXPECT_EQ(actuator->getCallCounter(), 0);

	monitor.update(14);
	EXPECT_EQ(actuator->getCallCounter(), 0);

	monitor.update(15);
	EXPECT_EQ(actuator->getCallCounter(), 0);

	monitor.update(16);
	EXPECT_EQ(actuator->getCallCounter(), 1);

	monitor.update(17);
	EXPECT_EQ(actuator->getCallCounter(), 2);
}

TEST(ThresholdSensorMonitor, TriggerOnlyOnceMonitorGreaterThanThreshold) {
	ThresholdSensorMonitorActuator* actuator = new ThresholdSensorMonitorActuator;
	ThresholdSensorMonitor monitor(15, MonitorThresholdType::GreaterThan, MonitorTriggerType::TriggerOnlyOnce, actuator);

	EXPECT_EQ(actuator->getCallCounter(), 0);

	monitor.update(14);
	EXPECT_EQ(actuator->getCallCounter(), 0);

	monitor.update(15);
	EXPECT_EQ(actuator->getCallCounter(), 0);

	monitor.update(16);
	EXPECT_EQ(actuator->getCallCounter(), 1);

	monitor.update(17);
	EXPECT_EQ(actuator->getCallCounter(), 1);
}