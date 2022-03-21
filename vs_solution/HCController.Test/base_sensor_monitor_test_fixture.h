#pragma once

#include "pch.h"

#include "base_monitor.h"
#include "base_monitor_sensor.h"
#include "base_monitor_actuator.h"

namespace HCControllerTests {
	class BaseSensorMonitorTestFixture : public ::testing::Test, public BaseMonitorSensor, public BaseMonitorActuator {
	protected:
		int sensorValue = 0;

		virtual BaseMonitor* getMonitorInstance() = 0;

		void updateValue(int sensorValue);

	public:
		virtual int readValue() override;
		void setSensorValue(int value);
	};
}