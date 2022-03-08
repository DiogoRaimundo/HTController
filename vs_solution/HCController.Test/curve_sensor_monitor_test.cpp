#include <iostream>
#include "gtest/gtest.h"

#include "pch.h"

#include "base_monitor_sensor.h"
#include "base_monitor_actuator.h"
#include "curve_sensor_monitor.h"

class CurveSensorMonitorTestFixture : public ::testing::Test, public BaseMonitorSensor, public BaseMonitorActuator {
private:
	int sensorValue = 0;
	int outputValue = 0;

protected:
	virtual int readValue() override {
		return sensorValue;
	}

	void setSensorValue(int value) {
		sensorValue = value;
	}

	virtual void triggerActuator() override {
		outputValue = sensorValue;
	}

	int getOutputValue() {
		return outputValue;
	}
};

TEST_F(CurveSensorMonitorTestFixture, TestInitialization) {
	CurveSensorMonitor monitor();

	EXPECT_EQ(getOutputValue(), 0);
}