#pragma once

#include "../../../Fixtures/Monitors/BaseMonitor/base_sensor_monitor_test_fixture.h"
#include "Monitors/ThresholdMonitor/threshold_sensor_monitor.h"

namespace HCControllerTests {
	class ThresholdSensorMonitorTestFixture : public BaseSensorMonitorTestFixture {
	private:
		ThresholdSensorMonitor* monitor = nullptr;
		int callbackCallCounter = 0;

	protected:
		void setMonitorInstance(ThresholdSensorMonitor* monitor);
		virtual BaseMonitor* getMonitorInstance() override;

		virtual void triggerActuator(int triggerValue) override;

		int getCallCounter();

		void updateAndExpectCallCount(int sensorValue, int expectedCallCount);

	public:
		~ThresholdSensorMonitorTestFixture();
	};
}