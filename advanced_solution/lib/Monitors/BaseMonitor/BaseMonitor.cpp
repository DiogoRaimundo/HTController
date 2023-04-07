#include "BaseMonitor.h"

BaseMonitor::BaseMonitor(BaseMonitorSensor* triggerSensor, BaseMonitorActuator* triggerActuator) {
	this->triggerSensor = triggerSensor;
	this->triggerActuator = triggerActuator;
}