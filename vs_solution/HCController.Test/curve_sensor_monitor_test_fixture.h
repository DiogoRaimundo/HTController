#pragma once

#include "base_sensor_monitor_test_fixture.h"
#include "curve_sensor_monitor.h"

namespace HCControllerTests {
	class CurveSensorMonitorTestFixture : public BaseSensorMonitorTestFixture {
	private:
		int outputValue = 0;

	protected:
		virtual void triggerActuator(int triggerValue) override;

		int getOutputValue();
		void updateAndExpectCallCount(CurveSensorMonitor* monitor, int sensorValue, int expectedCallCount);
	};

}