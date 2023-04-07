#pragma once

#include "../BaseMonitor/BaseMonitor.h"
#include "MonitorThresholdType.h"
#include "MonitorTriggerType.h"

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