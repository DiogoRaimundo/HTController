#include <iostream>
#include "gtest/gtest.h"

#include "pch.h"

#include "curve_sensor_monitor_test_fixture.h"

#include "curve_sensor_monitor.h"

namespace HCControllerTests {
	TEST_F(CurveSensorMonitorTestFixture, TestInitialization) {
		CurveSensorMonitor monitor();

		EXPECT_EQ(getOutputValue(), 0);
	}

	TEST_F(CurveSensorMonitorTestFixture, SetOneCurvePoint) {
		CurveSensorMonitor* monitor = new CurveSensorMonitor(this, this);

		monitor->addPoint(0, 50);

		EXPECT_EQ(monitor->getPointCount(), 1);
		EXPECT_EQ(monitor->getCurveValue(0), 50);
		EXPECT_EQ(monitor->getCurveValue(100), -1);

		/*updateAndExpectCallCount(monitor, 0, 50);
		updateAndExpectCallCount(monitor, 10, 100);
		updateAndExpectCallCount(monitor, 2048, 200);*/
	}

	TEST_F(CurveSensorMonitorTestFixture, SetTwoCurvePoints) {
		CurveSensorMonitor* monitor = new CurveSensorMonitor(this, this);

		monitor->addPoint(0, 50);
		monitor->addPoint(100, 150);

		EXPECT_EQ(monitor->getPointCount(), 2);
		EXPECT_EQ(monitor->getCurveValue(0), 50);
		EXPECT_EQ(monitor->getCurveValue(100), 150);

		//	updateAndExpectCallCount(monitor, 0, 50);
		//	updateAndExpectCallCount(monitor, 10, 100);
		//	updateAndExpectCallCount(monitor, 20, 200);
	}

	TEST_F(CurveSensorMonitorTestFixture, SetThreeCurvePointsWithLastInMid) {
		CurveSensorMonitor* monitor = new CurveSensorMonitor(this, this);

		monitor->addPoint(0, 50);
		monitor->addPoint(100, 150);
		monitor->addPoint(50, 100);

		EXPECT_EQ(monitor->getPointCount(), 3);
		EXPECT_EQ(monitor->getCurveValue(0), 50);
		EXPECT_EQ(monitor->getCurveValue(50), 100);
		EXPECT_EQ(monitor->getCurveValue(100), 150);

		//	updateAndExpectCallCount(monitor, 0, 50);
		//	updateAndExpectCallCount(monitor, 10, 100);
		//	updateAndExpectCallCount(monitor, 20, 200);
	}

	TEST_F(CurveSensorMonitorTestFixture, SetThreeCurvePointsWithLastInStart) {
		CurveSensorMonitor* monitor = new CurveSensorMonitor(this, this);

		monitor->addPoint(50, 100);
		monitor->addPoint(100, 150);
		monitor->addPoint(0, 50);

		EXPECT_EQ(monitor->getPointCount(), 3);
		EXPECT_EQ(monitor->getCurveValue(0), 50);
		EXPECT_EQ(monitor->getCurveValue(50), 100);
		EXPECT_EQ(monitor->getCurveValue(100), 150);

		//	updateAndExpectCallCount(monitor, 0, 50);
		//	updateAndExpectCallCount(monitor, 10, 100);
		//	updateAndExpectCallCount(monitor, 20, 200);
	}

	TEST_F(CurveSensorMonitorTestFixture, SetThreeCurvePointsWithLastInEnd) {
		CurveSensorMonitor* monitor = new CurveSensorMonitor(this, this);

		monitor->addPoint(0, 50);
		monitor->addPoint(50, 100);
		monitor->addPoint(100, 150);

		EXPECT_EQ(monitor->getPointCount(), 3);
		EXPECT_EQ(monitor->getCurveValue(0), 50);
		EXPECT_EQ(monitor->getCurveValue(50), 100);
		EXPECT_EQ(monitor->getCurveValue(100), 150);

		//	updateAndExpectCallCount(monitor, 0, 50);
		//	updateAndExpectCallCount(monitor, 10, 100);
		//	updateAndExpectCallCount(monitor, 20, 200);
	}


	TEST_F(CurveSensorMonitorTestFixture, SetAndResetACurvePoint) {
		CurveSensorMonitor* monitor = new CurveSensorMonitor(this, this);

		monitor->addPoint(0, 50);

		EXPECT_EQ(monitor->getPointCount(), 1);
		EXPECT_EQ(monitor->getCurveValue(0), 50);

		monitor->addPoint(0, 100);

		EXPECT_EQ(monitor->getPointCount(), 1);
		EXPECT_EQ(monitor->getCurveValue(0), 100);

		/*updateAndExpectCallCount(monitor, 0, 50);
		updateAndExpectCallCount(monitor, 10, 100);
		updateAndExpectCallCount(monitor, 2048, 200);*/
	}
}