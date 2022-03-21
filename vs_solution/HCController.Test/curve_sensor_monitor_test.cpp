#include <iostream>
#include "gtest/gtest.h"

#include "pch.h"

#include "curve_sensor_monitor_test_fixture.h"

#include "curve_sensor_monitor.h"

namespace HCControllerTests {
	/*TEST_F(CurveSensorMonitorTestFixture, TestInitialization) {
		CurveSensorMonitor monitor();

		EXPECT_EQ(getOutputValue(), 0);
	}*/

	TEST_F(CurveSensorMonitorTestFixture, SetOnePoint) {
		CurveSensorMonitor* monitor = new CurveSensorMonitor(this, this);
		setMonitorInstance(monitor);

		monitor->addPoint(0, 50);

		assertPointCount(1);
		assertPointValue(0, 50);
		assertPointValue(100, -1);
	}

	TEST_F(CurveSensorMonitorTestFixture, SetTwoPoints) {
		CurveSensorMonitor* monitor = new CurveSensorMonitor(this, this);
		setMonitorInstance(monitor);

		monitor->addPoint(0, 50);
		monitor->addPoint(100, 150);

		assertPointCount(2);
		assertPointValue(0, 50);
		assertPointValue(100, 150);
	}

	TEST_F(CurveSensorMonitorTestFixture, SetThreePointsWithLastInMid) {
		CurveSensorMonitor* monitor = new CurveSensorMonitor(this, this);
		setMonitorInstance(monitor);

		monitor->addPoint(0, 50);
		monitor->addPoint(100, 150);
		monitor->addPoint(50, 100);

		assertPointCount(3);
		assertPointValue(0, 50);
		assertPointValue(50, 100);
		assertPointValue(100, 150);
	}

	TEST_F(CurveSensorMonitorTestFixture, SetThreePointsWithLastInStart) {
		CurveSensorMonitor* monitor = new CurveSensorMonitor(this, this);
		setMonitorInstance(monitor);

		monitor->addPoint(50, 100);
		monitor->addPoint(100, 150);
		monitor->addPoint(0, 50);

		assertPointCount(3);
		assertPointValue(0, 50);
		assertPointValue(50, 100);
		assertPointValue(100, 150);
	}

	TEST_F(CurveSensorMonitorTestFixture, SetThreePointsWithLastInEnd) {
		CurveSensorMonitor* monitor = new CurveSensorMonitor(this, this);
		setMonitorInstance(monitor);

		monitor->addPoint(0, 50);
		monitor->addPoint(50, 100);
		monitor->addPoint(100, 150);

		assertPointCount(3);
		assertPointValue(0, 50);
		assertPointValue(50, 100);
		assertPointValue(100, 150);
	}

	TEST_F(CurveSensorMonitorTestFixture, SetAndResetAPoint) {
		CurveSensorMonitor* monitor = new CurveSensorMonitor(this, this);
		setMonitorInstance(monitor);

		monitor->addPoint(0, 50);

		assertPointCount(1);
		assertPointValue(0, 50);

		monitor->addPoint(0, 100);

		assertPointCount(1);
		assertPointValue(0, 100);
	}

	TEST_F(CurveSensorMonitorTestFixture, GetInterpolatedPoint) {
		CurveSensorMonitor* monitor = new CurveSensorMonitor(this, this);
		setMonitorInstance(monitor);

		monitor->addPoint(0, 50);
		monitor->addPoint(100, 200);

		updateAndExpectOutputValue(50, 125);
	}
}