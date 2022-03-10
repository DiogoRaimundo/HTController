#include "pch.h"

#include "threshold_sensor_monitor_test_fixture.h"

void ThresholdSensorMonitorTestFixture::triggerActuator() {
	callbackCallCounter++;
}

int ThresholdSensorMonitorTestFixture::getCallCounter() {
	return callbackCallCounter;
}

void ThresholdSensorMonitorTestFixture::updateAndExpectCallCount(ThresholdSensorMonitor* monitor, int sensorValue, int expectedCallCount) {
	setSensorValue(sensorValue);

	monitor->update();

	EXPECT_EQ(getCallCounter(), expectedCallCount);
}