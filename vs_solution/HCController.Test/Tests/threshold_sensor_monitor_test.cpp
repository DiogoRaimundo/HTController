#include "../pch.h"

#include "../Fixtures/Monitors/ThresholdMonitor/threshold_sensor_monitor_test_fixture.h"

#include "Monitors/ThresholdMonitor/threshold_sensor_monitor.h"
#include "Monitors/ThresholdMonitor/monitor_threshold_type.h"
#include "Monitors/ThresholdMonitor/monitor_trigger_type.h"

namespace HCControllerTests {
	TEST_F(ThresholdSensorMonitorTestFixture, TestInitialization)
	{
		ThresholdSensorMonitor monitor(15, MonitorThresholdType::GreaterThan, this, this);

		EXPECT_EQ(getCallCounter(), 0);
	}

	TEST_F(ThresholdSensorMonitorTestFixture, MonitorInitialization)
	{
		ThresholdSensorMonitor monitor(15, MonitorThresholdType::GreaterThan, this, this);

		int thresholdValue = monitor.getThresholdValue();

		EXPECT_EQ(thresholdValue, 15);
	}

	TEST_F(ThresholdSensorMonitorTestFixture, AllwaysTriggerIfGreaterThanThreshold)
	{
		ThresholdSensorMonitor* monitor = new ThresholdSensorMonitor(15, MonitorThresholdType::GreaterThan, this, this);
		setMonitorInstance(monitor);

		updateAndExpectCallCount(14, 0);
		updateAndExpectCallCount(15, 0);
		updateAndExpectCallCount(16, 1);
		updateAndExpectCallCount(17, 2);
	}

	TEST_F(ThresholdSensorMonitorTestFixture, TriggerOnlyOnceIfGreaterThanThreshold)
	{
		ThresholdSensorMonitor* monitor = new ThresholdSensorMonitor(15, MonitorThresholdType::GreaterThan, MonitorTriggerType::TriggerOnlyOnce, this, this);
		setMonitorInstance(monitor);

		updateAndExpectCallCount(14, 0);
		updateAndExpectCallCount(15, 0);
		updateAndExpectCallCount(16, 1);
		updateAndExpectCallCount(17, 1);
	}

	TEST_F(ThresholdSensorMonitorTestFixture, AllwaysTriggerIfGreaterOrEqualThanThreshold)
	{
		ThresholdSensorMonitor* monitor = new ThresholdSensorMonitor(15, MonitorThresholdType::GreaterOrEqualThan, this, this);
		setMonitorInstance(monitor);

		updateAndExpectCallCount(14, 0);
		updateAndExpectCallCount(15, 1);
		updateAndExpectCallCount(16, 2);
	}

	TEST_F(ThresholdSensorMonitorTestFixture, AllwaysTriggerIfLessThanThreshold)
	{
		ThresholdSensorMonitor* monitor = new ThresholdSensorMonitor(15, MonitorThresholdType::LessThan, this, this);
		setMonitorInstance(monitor);

		updateAndExpectCallCount(16, 0);
		updateAndExpectCallCount(15, 0);
		updateAndExpectCallCount(14, 1);
	}

	TEST_F(ThresholdSensorMonitorTestFixture, AllwaysTriggerIfrLessOrEqualThanThreshold)
	{
		ThresholdSensorMonitor* monitor = new ThresholdSensorMonitor(15, MonitorThresholdType::LessOrEqualThan, this, this);
		setMonitorInstance(monitor);

		updateAndExpectCallCount(16, 0);
		updateAndExpectCallCount(15, 1);
		updateAndExpectCallCount(14, 2);
	}

	TEST_F(ThresholdSensorMonitorTestFixture, TriggerOnlyOnceIfGreaterThanThresholdAndResetsIfNot)
	{
		ThresholdSensorMonitor* monitor = new ThresholdSensorMonitor(15, MonitorThresholdType::GreaterThan, MonitorTriggerType::TriggerOnlyOnce, this, this);
		setMonitorInstance(monitor);

		updateAndExpectCallCount(14, 0);
		updateAndExpectCallCount(15, 0);
		updateAndExpectCallCount(16, 1);
		updateAndExpectCallCount(15, 1);
		updateAndExpectCallCount(16, 2);
	}
}