#include "threshold_sensor_monitor.h"
#include "monitor_threshold_type.h"
#include "monitor_trigger_type.h"

ThresholdSensorMonitor::ThresholdSensorMonitor(int thresholdValue, MonitorThresholdType thresholdType, MonitorTriggerType triggerType, BaseMonitorSensor* triggerSensor, BaseMonitorActuator* triggerActuator) :
	BaseMonitor(triggerSensor, triggerActuator)
{
	this->thresholdValue = thresholdValue;
	this->thresholdType = thresholdType;

	this->triggerType = triggerType;
	this->hasBeenTriggered = false;
}

int ThresholdSensorMonitor::getThresholdValue() {
	return this->thresholdValue;
}

void ThresholdSensorMonitor::setThresholdValue(int value) {
	this->thresholdValue = value;
}

bool ThresholdSensorMonitor::isTriggeringValue(int value) {
	switch (this->thresholdType)
	{
	case MonitorThresholdType::GreaterThan:
		return value > this->thresholdValue;

	case MonitorThresholdType::GreaterOrEqualThan:
		return value >= this->thresholdValue;

	case MonitorThresholdType::LessThan:
		return value < this->thresholdValue;

	case MonitorThresholdType::LessOrEqualThan:
		return value <= this->thresholdValue;
	}

	return false;
}

void ThresholdSensorMonitor::fireTrigger(int triggerValue) {
	this->hasBeenTriggered = true;
	this->triggerActuator->triggerActuator(triggerValue);
}

void ThresholdSensorMonitor::resetTrigger() {
	this->hasBeenTriggered = false;
}

void ThresholdSensorMonitor::update() {
	int sensorValue = triggerSensor->readValue();

	if (isTriggeringValue(sensorValue)) {
		if (this->hasBeenTriggered && this->triggerType == MonitorTriggerType::TriggerOnlyOnce) {
			return;
		}

		this->fireTrigger(sensorValue);
	}
	else {
		this->resetTrigger();
	}
}