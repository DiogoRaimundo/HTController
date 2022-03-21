#include "pch.h"

#include "threshold_sensor_monitor_test_fixture.h"

using namespace HCControllerTests;

ThresholdSensorMonitorTestFixture::~ThresholdSensorMonitorTestFixture() {
	if (monitor != nullptr) {
		delete monitor;
	}
}

void ThresholdSensorMonitorTestFixture::setMonitorInstance(ThresholdSensorMonitor* monitor) {
	this->monitor = monitor;
}

BaseMonitor* ThresholdSensorMonitorTestFixture::getMonitorInstance() {
	return monitor;
}

void ThresholdSensorMonitorTestFixture::triggerActuator(int triggerValue) {
	callbackCallCounter++;
}

int ThresholdSensorMonitorTestFixture::getCallCounter() {
	return callbackCallCounter;
}

void ThresholdSensorMonitorTestFixture::updateAndExpectCallCount(int sensorValue, int expectedCallCount) {
	setSensorValue(sensorValue);

	monitor->update();

	EXPECT_EQ(getCallCounter(), expectedCallCount);
}