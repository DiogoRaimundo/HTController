#include "pch.h"
#include "threshold_sensor_monitor.h"
#include "monitor_threshold_type.h"
#include "monitor_trigger_type.h"

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

void ThresholdSensorMonitor::fireTrigger() {
	this->hasBeenTriggered = true;
	this->triggerActuator->triggerActuator();
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

		this->fireTrigger();
	}
	else {
		this->resetTrigger();
	}
}