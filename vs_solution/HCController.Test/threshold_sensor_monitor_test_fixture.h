#pragma once

#include "base_sensor_monitor_test_fixture.h"
#include "threshold_sensor_monitor.h"

class ThresholdSensorMonitorTestFixture : public BaseSensorMonitorTestFixture {
private:
	int callbackCallCounter = 0;

public:
	virtual void triggerActuator() override;

	int getCallCounter();

	void updateAndExpectCallCount(ThresholdSensorMonitor* monitor, int sensorValue, int expectedCallCount);
};