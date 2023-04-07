#pragma once

#include "../BaseMonitor/BaseMonitor.h"

#define CURVE_LENGTH 1024

class CurveSensorMonitor : public BaseMonitor {
private:
	int pointCount;

	void resizeArrayAndAddPoint(int xValue, int yValue);
	int getInterpoletedValue(int xValue,
		int closestMinXValue, int closestMinYValue, int closestMaxXValue, int closestMaxYValue);
	int getExtrapoletedValue(int xValue,
		int closestMinXValue, int closestMinYValue, int closestMaxXValue, int closestMaxYValue);

public:
	CurveSensorMonitor(BaseMonitorSensor* triggerSensor, BaseMonitorActuator* triggerActuator);
	~CurveSensorMonitor();

	virtual void update() override;

	void addPoint(int xValue, int yValue);
	int getCurveValue(int xValue);
	int getPointCount();

	// TODO To remove
	int* pointValues;
};