#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#include "pch.h"
#include "base_monitor.h"
#include "monitor_threshold_type.h"
#include "monitor_trigger_type.h"

class ThresholdSensorMonitor : BaseMonitor {
private:
	int thresholdValue;
	MonitorThresholdType thresholdType;

	MonitorTriggerType triggerType;
	bool hasBeenTriggered;

	bool isTriggeringValue(int value);
	void fireTrigger();
	void resetTrigger();

public:
	ThresholdSensorMonitor(int thresholdValue, MonitorThresholdType thresholdType, BaseMonitorSensor* triggerSensor, BaseMonitorActuator* triggerActuator) :
		ThresholdSensorMonitor(thresholdValue, thresholdType, MonitorTriggerType::TriggerAllways, triggerSensor, triggerActuator) {}

	ThresholdSensorMonitor(int thresholdValue, MonitorThresholdType thresholdType, MonitorTriggerType triggerType, BaseMonitorSensor* triggerSensor, BaseMonitorActuator* triggerActuator) :
		BaseMonitor(triggerSensor, triggerActuator)
	{
		this->thresholdValue = thresholdValue;
		this->thresholdType = thresholdType;

		this->triggerType = triggerType;
		this->hasBeenTriggered = false;
	}

	int getThresholdValue();
	void setThresholdValue(int value);
	virtual void update() override;
};