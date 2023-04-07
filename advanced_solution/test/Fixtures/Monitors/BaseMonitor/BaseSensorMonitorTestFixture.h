#pragma once

#include "../lib/Monitors/BaseMonitor/BaseMonitor.h"
#include "../lib/Monitors/BaseMonitor/BaseMonitorSensor.h"
#include "../lib/Monitors/BaseMonitor/BaseMonitorActuator.h"

namespace HCControllerTests
{
	class BaseSensorMonitorTestFixture : public ::testing::Test, public BaseMonitorSensor, public BaseMonitorActuator
	{
	protected:
		int sensorValue = 0;

		virtual BaseMonitor *getMonitorInstance() = 0;

		void updateValue(int sensorValue);

	public:
		virtual int readValue() override;
		void setSensorValue(int value);
	};
}