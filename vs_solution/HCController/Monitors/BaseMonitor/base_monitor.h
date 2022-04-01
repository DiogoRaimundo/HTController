#pragma once

#include "base_monitor_sensor.h"
#include "base_monitor_actuator.h"

class BaseMonitor {
protected:
	BaseMonitorSensor* triggerSensor;
	BaseMonitorActuator* triggerActuator;

	BaseMonitor(BaseMonitorSensor* triggerSensor, BaseMonitorActuator* triggerActuator);

public:
	virtual void update() = 0;
};

