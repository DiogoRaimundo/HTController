#include "pch.h"

#include "curve_sensor_monitor_test_fixture.h"


void CurveSensorMonitorTestFixture::triggerActuator() {
	outputValue = sensorValue;
}

int CurveSensorMonitorTestFixture::getOutputValue() {
	return outputValue;
}
