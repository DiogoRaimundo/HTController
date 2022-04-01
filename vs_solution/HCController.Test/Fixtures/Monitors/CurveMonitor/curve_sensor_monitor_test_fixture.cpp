#include "../../../pch.h"

#include "curve_sensor_monitor_test_fixture.h"

using namespace HCControllerTests;

CurveSensorMonitorTestFixture::~CurveSensorMonitorTestFixture()
{
	if (monitor != nullptr) {
		delete monitor;
	}
}

void CurveSensorMonitorTestFixture::setMonitorInstance(CurveSensorMonitor* monitor)
{
	this->monitor = monitor;
}

BaseMonitor* CurveSensorMonitorTestFixture::getMonitorInstance()
{
	return monitor;
}

void CurveSensorMonitorTestFixture::triggerActuator(int triggerValue)
{
	outputValue = triggerValue;
}

int CurveSensorMonitorTestFixture::getOutputValue()
{
	return outputValue;
}

void CurveSensorMonitorTestFixture::updateAndExpectOutputValue(int sensorValue, int expectedOutputValue)
{
	setSensorValue(sensorValue);

	monitor->update();

	EXPECT_EQ(getOutputValue(), expectedOutputValue);
}

void CurveSensorMonitorTestFixture::assertPointCount(int expectedPointCount)
{
	EXPECT_EQ(monitor->getPointCount(), expectedPointCount);
}

void CurveSensorMonitorTestFixture::assertPointValue(int pointXValue, int expectedPointYValue)
{
	EXPECT_EQ(monitor->getCurveValue(pointXValue), expectedPointYValue);
}