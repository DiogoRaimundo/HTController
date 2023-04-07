#pragma once

class BaseMonitorActuator {
public:
	virtual void triggerActuator(int triggerValue) = 0;
};