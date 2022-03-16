#include "pch.h"

#include "curve_sensor_monitor_test_fixture.h"

using namespace HCControllerTests;

void CurveSensorMonitorTestFixture::triggerActuator(int triggerValue) {
	outputValue = triggerValue;
}

int CurveSensorMonitorTestFixture::getOutputValue() {
	return outputValue;
}

void CurveSensorMonitorTestFixture::updateAndExpectCallCount(CurveSensorMonitor* monitor, int sensorValue, int expectedCallCount) {
	setSensorValue(sensorValue);

	monitor->update();

	EXPECT_EQ(getOutputValue(), expectedCallCount);
}