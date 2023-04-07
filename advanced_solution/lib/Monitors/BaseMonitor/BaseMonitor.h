#pragma once

#include "BaseMonitorSensor.h"
#include "BaseMonitorActuator.h"

class BaseMonitor {
protected:
	BaseMonitorSensor* triggerSensor;
	BaseMonitorActuator* triggerActuator;

	BaseMonitor(BaseMonitorSensor* triggerSensor, BaseMonitorActuator* triggerActuator);

public:
	virtual void update() = 0;
};

