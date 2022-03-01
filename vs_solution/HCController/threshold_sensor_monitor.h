#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#include "pch.h"
#include "monitor_threshold_type.h"
#include "monitor_trigger_type.h"
#include "base_monitor_actuator.h"

class ThresholdSensorMonitor {
private:
	int thresholdValue;
	MonitorThresholdType thresholdType;

	MonitorTriggerType triggerType;
	BaseMonitorActuator* triggerActuator;
	bool hasBeenTriggered;

	bool isTriggeringValue(int value);

public:
	ThresholdSensorMonitor(int thresholdValue, MonitorThresholdType thresholdType, BaseMonitorActuator* triggerActuator) :
		ThresholdSensorMonitor(thresholdValue, thresholdType, MonitorTriggerType::TriggerAllways, triggerActuator) {}

	ThresholdSensorMonitor(int thresholdValue, MonitorThresholdType thresholdType, MonitorTriggerType triggerType, BaseMonitorActuator* triggerActuator) {
		this->thresholdValue = thresholdValue;
		this->thresholdType = thresholdType;

		this->triggerType = triggerType;
		this->triggerActuator = triggerActuator;
		this->hasBeenTriggered = false;
	}

	int getThresholdValue();
	void setThresholdValue(int value);
	void update(int value);
};