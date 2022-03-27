#include "pch.h"

#include "curve_sensor_monitor.h"

CurveSensorMonitor::CurveSensorMonitor(BaseMonitorSensor* triggerSensor, BaseMonitorActuator* triggerActuator) :
	BaseMonitor(triggerSensor, triggerActuator)
{
	pointCount = 0;
	pointValues = nullptr;
}

CurveSensorMonitor::~CurveSensorMonitor()
{
	if (pointCount > 0) {
		delete[] pointValues;
	}
}

void CurveSensorMonitor::update()
{
	int sensorValue = triggerSensor->readValue();

	if (sensorValue >= 0 && sensorValue < CURVE_LENGTH) {
		triggerActuator->triggerActuator(getCurveValue(sensorValue));
	}
}

void CurveSensorMonitor::addPoint(int xValue, int yValue)
{
	for (int i = 0; i < pointCount; i += 2)
	{
		if (pointValues[i] == xValue) {
			pointValues[i + 1] = yValue;
			return;
		}
	}

	resizeArrayAndAddPoint(xValue, yValue);
}

int CurveSensorMonitor::getCurveValue(int xValue)
{
	int closestMinXValue = -1;
	int closestMinYValue = -1;
	int closestMaxXValue = -1;
	int closestMaxYValue = -1;

	int currXValue;
	int currYValue;
	for (int i = 0; i < pointCount; i += 2)
	{
		currXValue = pointValues[i];
		currYValue = pointValues[i + 1];

		if (currXValue == xValue) {
			return currYValue;
		}
		else if (currXValue < xValue) {
			closestMinXValue = currXValue;
			closestMinYValue = currYValue;
		}
		else {
			closestMaxXValue = currXValue;
			closestMaxYValue = currYValue;
		}
	}

	if (closestMinXValue == -1 || closestMinYValue == -1 ||
		closestMaxXValue == -1 || closestMaxYValue == -1) {
		return getExtrapoletedValue(xValue, closestMinXValue, closestMinYValue, closestMaxXValue, closestMaxYValue);
	}

	return getInterpoletedValue(xValue, closestMinXValue, closestMinYValue, closestMaxXValue, closestMaxYValue);
}

int CurveSensorMonitor::getPointCount()
{
	return pointCount / 2;
}

void CurveSensorMonitor::resizeArrayAndAddPoint(int xValue, int yValue)
{
	int newPointCount = pointCount + 2;
	int* newArray = new int[newPointCount];

	if (pointCount == 0) {
		newArray[0] = xValue;
		newArray[1] = yValue;
	}
	else {
		if (xValue < pointValues[0]) {
			newArray[0] = xValue;
			newArray[1] = yValue;

			for (int i = 0; i < pointCount; i++)
			{
				newArray[i + 2] = pointValues[i];
			}
		}
		else if (xValue > pointValues[pointCount - 2]) {
			for (int i = 0; i < pointCount; i++)
			{
				newArray[i] = pointValues[i];
			}

			newArray[pointCount] = xValue;
			newArray[pointCount + 1] = yValue;
		}
		else {
			int offset = 0;
			for (int i = 0; i < pointCount; i++)
			{
				if (xValue < pointValues[i]) {
					newArray[i] = xValue;
#pragma warning( disable: 6386 )
					newArray[i + 1] = yValue;

					offset = 2;
				}

				newArray[i + offset] = pointValues[i];

				i++;
				newArray[i + offset] = pointValues[i];
			}
		}
	}

	delete[] pointValues;
	pointCount = newPointCount;
	pointValues = newArray;
}

int CurveSensorMonitor::getInterpoletedValue(int xValue,
	int closestMinXValue, int closestMinYValue, int closestMaxXValue, int closestMaxYValue)
{
	int minYValueContribution = closestMinYValue * (closestMaxXValue - xValue);
	int maxYValueContribution = closestMaxYValue * (xValue - closestMinXValue);
	int yValueContributions = minYValueContribution + maxYValueContribution;

	int closestXValuesDistance = closestMaxXValue - closestMinXValue;

	int yValue = yValueContributions / closestXValuesDistance;

	int contributionRemaining = yValueContributions % closestXValuesDistance;
	if (contributionRemaining < 0) {
		contributionRemaining *= -1;
	}

	if (contributionRemaining >= closestXValuesDistance / 2.0) {
		yValue += yValue > 0 ? 1 : -1;
	}

	return yValue;
}

int CurveSensorMonitor::getExtrapoletedValue(int xValue,
	int closestMinXValue, int closestMinYValue, int closestMaxXValue, int closestMaxYValue)
{
	return -1;
}