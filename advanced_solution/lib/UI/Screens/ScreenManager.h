#pragma once

#include "ScreenState.h"

class ScreenManager {
private:
	ScreenState* acOnThresholdMenuOption;
	ScreenState* temperatureCurveMenuOption;
	ScreenState* screenTimeoutMenuOption;

public:
	ScreenManager();

	ScreenState* getAcOnThresholdMenuOption();
	ScreenState* getTemperatureCurveMenuOption();
	ScreenState* getScreenTimeoutMenuOption();
};