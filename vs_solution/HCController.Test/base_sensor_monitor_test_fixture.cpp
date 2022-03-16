#include "gtest/gtest.h"

#include "pch.h"

#include "base_sensor_monitor_test_fixture.h"

#include "base_monitor.h"
#include "base_monitor_sensor.h"
#include "base_monitor_actuator.h"

using namespace HCControllerTests;

void BaseSensorMonitorTestFixture::updateValue(BaseMonitor* monitor, int sensorValue) {
	setSensorValue(sensorValue);

	monitor->update();
}

int BaseSensorMonitorTestFixture::readValue() {
	return sensorValue;
}

void BaseSensorMonitorTestFixture::setSensorValue(int value) {
	sensorValue = value;
}