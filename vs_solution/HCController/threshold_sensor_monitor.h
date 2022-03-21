#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#include "pch.h"
#include "base_monitor.h"
#include "monitor_threshold_type.h"
#include "monitor_trigger_type.h"

class ThresholdSensorMonitor : public BaseMonitor {
private:
	int thresholdValue;
	MonitorThresholdType thresholdType;

	MonitorTriggerType triggerType;
	bool hasBeenTriggered;

	bool isTriggeringValue(int value);
	void fireTrigger(int triggerValue);
	void resetTrigger();

public:
	ThresholdSensorMonitor(int thresholdValue, MonitorThresholdType thresholdType, BaseMonitorSensor* triggerSensor, BaseMonitorActuator* triggerActuator) :
		ThresholdSensorMonitor(thresholdValue, thresholdType, MonitorTriggerType::TriggerAllways, triggerSensor, triggerActuator) {}

	ThresholdSensorMonitor(int thresholdValue, MonitorThresholdType thresholdType, MonitorTriggerType triggerType, BaseMonitorSensor* triggerSensor, BaseMonitorActuator* triggerActuator);

	int getThresholdValue();
	void setThresholdValue(int value);
	virtual void update() override;
};