#include <iostream>
#include "gtest/gtest.h"

#include "pch.h"

#include "threshold_sensor_monitor.h"
#include "monitor_threshold_type.h"
#include "monitor_trigger_type.h"
#include "base_monitor_actuator.h"

class ThresholdSensorMonitorTestFixture : public ::testing::Test, public BaseMonitorActuator {
private:
	int callbackCallCounter = 0;

protected:
	virtual void triggerActuator() override {
		callbackCallCounter++;
	}

	int getCallCounter() {
		return callbackCallCounter;
	}

	void updateAndExpectCallCount(ThresholdSensorMonitor* monitor, int updateValue, int expectedCallCount) {
		monitor->update(updateValue);
		EXPECT_EQ(getCallCounter(), expectedCallCount);
	}
};

TEST_F(ThresholdSensorMonitorTestFixture, TestInitialization) {
	ThresholdSensorMonitor monitor(15, MonitorThresholdType::GreaterThan, this);

	EXPECT_EQ(getCallCounter(), 0);
}

TEST_F(ThresholdSensorMonitorTestFixture, MonitorInitialization) {
	ThresholdSensorMonitor monitor(15, MonitorThresholdType::GreaterThan, this);

	int thresholdValue = monitor.getThresholdValue();

	EXPECT_EQ(thresholdValue, 15);
}

TEST_F(ThresholdSensorMonitorTestFixture, AllwaysTriggerMonitorGreaterThanThreshold) {
	ThresholdSensorMonitor* monitor = new ThresholdSensorMonitor(15, MonitorThresholdType::GreaterThan, this);

	updateAndExpectCallCount(monitor, 14, 0);
	updateAndExpectCallCount(monitor, 15, 0);
	updateAndExpectCallCount(monitor, 16, 1);
	updateAndExpectCallCount(monitor, 17, 2);
}

TEST_F(ThresholdSensorMonitorTestFixture, TriggerOnlyOnceMonitorGreaterThanThreshold) {
	ThresholdSensorMonitor* monitor = new ThresholdSensorMonitor(15, MonitorThresholdType::GreaterThan, MonitorTriggerType::TriggerOnlyOnce, this);

	updateAndExpectCallCount(monitor, 14, 0);
	updateAndExpectCallCount(monitor, 15, 0);
	updateAndExpectCallCount(monitor, 16, 1);
	updateAndExpectCallCount(monitor, 17, 1);
}

TEST_F(ThresholdSensorMonitorTestFixture, AllwaysTriggerMonitorGreaterOrEqualThanThreshold) {
	ThresholdSensorMonitor* monitor = new ThresholdSensorMonitor(15, MonitorThresholdType::GreaterOrEqualThan, this);

	updateAndExpectCallCount(monitor, 14, 0);
	updateAndExpectCallCount(monitor, 15, 1);
	updateAndExpectCallCount(monitor, 16, 2);
}

TEST_F(ThresholdSensorMonitorTestFixture, AllwaysTriggerMonitorLessThanThreshold) {
	ThresholdSensorMonitor* monitor = new ThresholdSensorMonitor(15, MonitorThresholdType::LessThan, this);

	updateAndExpectCallCount(monitor, 16, 0);
	updateAndExpectCallCount(monitor, 15, 0);
	updateAndExpectCallCount(monitor, 14, 1);
}

TEST_F(ThresholdSensorMonitorTestFixture, AllwaysTriggerMonitorLessOrEqualThanThreshold) {
	ThresholdSensorMonitor* monitor = new ThresholdSensorMonitor(15, MonitorThresholdType::LessOrEqualThan, this);

	updateAndExpectCallCount(monitor, 16, 0);
	updateAndExpectCallCount(monitor, 15, 1);
	updateAndExpectCallCount(monitor, 14, 2);
}