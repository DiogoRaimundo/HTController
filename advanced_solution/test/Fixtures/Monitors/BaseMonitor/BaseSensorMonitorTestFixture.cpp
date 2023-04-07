#include "BaseSensorMonitorTestFixture.h"

#include "../lib/Monitors/BaseMonitor/BaseMonitor.h"
#include "../lib/Monitors/BaseMonitor/BaseMonitorSensor.h"
#include "../lib/Monitors/BaseMonitor/BaseMonitorActuator.h"

using namespace HCControllerTests;

void BaseSensorMonitorTestFixture::updateValue(int sensorValue)
{
	setSensorValue(sensorValue);

	BaseMonitor *monitor = getMonitorInstance();
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