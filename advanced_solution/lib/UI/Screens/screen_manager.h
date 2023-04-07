#pragma once

#include "screen_state.h"

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