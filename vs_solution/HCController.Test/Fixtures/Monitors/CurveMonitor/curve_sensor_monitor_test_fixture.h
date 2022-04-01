#pragma once

#include "../../../Fixtures/Monitors/BaseMonitor/base_sensor_monitor_test_fixture.h"
#include "Monitors/CurveMonitor/curve_sensor_monitor.h"

namespace HCControllerTests {
	class CurveSensorMonitorTestFixture : public BaseSensorMonitorTestFixture {
	private:
		CurveSensorMonitor* monitor = nullptr;
		int outputValue = 0;

	protected:
		void setMonitorInstance(CurveSensorMonitor* monitor);
		virtual BaseMonitor* getMonitorInstance() override;

		virtual void triggerActuator(int triggerValue) override;

		int getOutputValue();
		void updateAndExpectOutputValue(int sensorValue, int expectedCallCount);

		void assertPointCount(int expectedPointCount);
		void assertPointValue(int pointXValue, int expectedPointYValue);

	public:
		~CurveSensorMonitorTestFixture();
	};
}