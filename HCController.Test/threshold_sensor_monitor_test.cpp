#include "pch.h"
#include "threshold_sensor_monitor.h"

TEST(ThresholdSensorMonitor, MonitorInitialization) {
	ThresholdSensorMonitor monitor(15);

	int thresholdValue = monitor.getThresholdValue();

	EXPECT_EQ(thresholdValue, 15);
}