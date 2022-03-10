#pragma once

#include "base_sensor_monitor_test_fixture.h"

class CurveSensorMonitorTestFixture : public BaseSensorMonitorTestFixture {
private:
	int outputValue = 0;

protected:
	virtual void triggerActuator() override;

	int getOutputValue();
};

