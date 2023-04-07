#include "screen_manager.h"
#include "MenuScreens/SetAcOnThresholdScreen/set_ac_on_threshold_screen.h"
#include "MenuScreens/SetTemperatureCurveScreen/set_temperature_curve_screen.h"
#include "MenuScreens/SetScreenTimeoutScreen/set_screen_timeout_screen.h"

ScreenManager::ScreenManager() {
	this->acOnThresholdMenuOption = new SetAcOnThresholdScreen(this);
	this->temperatureCurveMenuOption = new SetTemperatureCurveScreen(this);
	this->screenTimeoutMenuOption = new SetScreenTimeoutScreen(this);
}

ScreenState* ScreenManager::getAcOnThresholdMenuOption() {
	return this->acOnThresholdMenuOption;
}

ScreenState* ScreenManager::getTemperatureCurveMenuOption() {
	return this->temperatureCurveMenuOption;
}

ScreenState* ScreenManager::getScreenTimeoutMenuOption() {
	return this->screenTimeoutMenuOption;
}