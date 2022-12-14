#include "../../../pch.h"

#include "base_sensor_monitor_test_fixture.h"

#include "Monitors/BaseMonitor/base_monitor.h"
#include "Monitors/BaseMonitor/base_monitor_sensor.h"
#include "Monitors/BaseMonitor/base_monitor_actuator.h"

using namespace HCControllerTests;

void BaseSensorMonitorTestFixture::updateValue(int sensorValue)
{
	setSensorValue(sensorValue);

	BaseMonitor* monitor = getMonitorInstance();
	monitor->update();
}

int BaseSensorMonitorTestFixture::readValue()
{
	return sensorValue;
}

void BaseSensorMonitorTestFixture::setSensorValue(int value)
{
	sensorValue = value;
}