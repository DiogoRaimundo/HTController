#pragma once

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers

#include "pch.h"

class ThresholdSensorMonitor {
private:
	int thresholdValue;

public:
	ThresholdSensorMonitor(int thresholdValue) {
		this->thresholdValue = thresholdValue;
	}

	int getThresholdValue();
};