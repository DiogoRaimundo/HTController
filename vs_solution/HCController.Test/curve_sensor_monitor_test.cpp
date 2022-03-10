#include <iostream>
#include "gtest/gtest.h"

#include "pch.h"

#include "curve_sensor_monitor_test_fixture.h"

#include "curve_sensor_monitor.h"

TEST_F(CurveSensorMonitorTestFixture, TestInitialization) {
	CurveSensorMonitor monitor();

	EXPECT_EQ(getOutputValue(), 0);
}

