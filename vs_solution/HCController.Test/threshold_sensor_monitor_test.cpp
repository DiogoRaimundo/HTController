#include <iostream>
#include "gtest/gtest.h"

#include "pch.h"

#include "threshold_sensor_monitor_test_fixture.h"

#include "threshold_sensor_monitor.h"
#include "monitor_threshold_type.h"
#include "monitor_trigger_type.h"

TEST_F(ThresholdSensorMonitorTestFixture, TestInitialization) {
	ThresholdSensorMonitor monitor(15, MonitorThresholdType::GreaterThan, this, this);

	EXPECT_EQ(getCallCounter(), 0);
}

TEST_F(ThresholdSensorMonitorTestFixture, MonitorInitialization) {
	ThresholdSensorMonitor monitor(15, MonitorThresholdType::GreaterThan, this, this);

	int thresholdValue = monitor.getThresholdValue();

	EXPECT_EQ(thresholdValue, 15);
}

TEST_F(ThresholdSensorMonitorTestFixture, AllwaysTriggerIfGreaterThanThreshold) {
	ThresholdSensorMonitor* monitor = new ThresholdSensorMonitor(15, MonitorThresholdType::GreaterThan, this, this);

	updateAndExpectCallCount(monitor, 14, 0);
	updateAndExpectCallCount(monitor, 15, 0);
	updateAndExpectCallCount(monitor, 16, 1);
	updateAndExpectCallCount(monitor, 17, 2);
}

TEST_F(ThresholdSensorMonitorTestFixture, TriggerOnlyOnceIfGreaterThanThreshold) {
	ThresholdSensorMonitor* monitor = new ThresholdSensorMonitor(15, MonitorThresholdType::GreaterThan, MonitorTriggerType::TriggerOnlyOnce, this, this);

	updateAndExpectCallCount(monitor, 14, 0);
	updateAndExpectCallCount(monitor, 15, 0);
	updateAndExpectCallCount(monitor, 16, 1);
	updateAndExpectCallCount(monitor, 17, 1);
}

TEST_F(ThresholdSensorMonitorTestFixture, AllwaysTriggerIfGreaterOrEqualThanThreshold) {
	ThresholdSensorMonitor* monitor = new ThresholdSensorMonitor(15, MonitorThresholdType::GreaterOrEqualThan, this, this);

	updateAndExpectCallCount(monitor, 14, 0);
	updateAndExpectCallCount(monitor, 15, 1);
	updateAndExpectCallCount(monitor, 16, 2);
}

TEST_F(ThresholdSensorMonitorTestFixture, AllwaysTriggerIfLessThanThreshold) {
	ThresholdSensorMonitor* monitor = new ThresholdSensorMonitor(15, MonitorThresholdType::LessThan, this, this);

	updateAndExpectCallCount(monitor, 16, 0);
	updateAndExpectCallCount(monitor, 15, 0);
	updateAndExpectCallCount(monitor, 14, 1);
}

TEST_F(ThresholdSensorMonitorTestFixture, AllwaysTriggerIfrLessOrEqualThanThreshold) {
	ThresholdSensorMonitor* monitor = new ThresholdSensorMonitor(15, MonitorThresholdType::LessOrEqualThan, this, this);

	updateAndExpectCallCount(monitor, 16, 0);
	updateAndExpectCallCount(monitor, 15, 1);
	updateAndExpectCallCount(monitor, 14, 2);
}

TEST_F(ThresholdSensorMonitorTestFixture, TriggerOnlyOnceIfGreaterThanThresholdAndResetsIfNot) {
	ThresholdSensorMonitor* monitor = new ThresholdSensorMonitor(15, MonitorThresholdType::GreaterThan, MonitorTriggerType::TriggerOnlyOnce, this, this);

	updateAndExpectCallCount(monitor, 14, 0);
	updateAndExpectCallCount(monitor, 15, 0);
	updateAndExpectCallCount(monitor, 16, 1);
	updateAndExpectCallCount(monitor, 15, 1);
	updateAndExpectCallCount(monitor, 16, 2);
}