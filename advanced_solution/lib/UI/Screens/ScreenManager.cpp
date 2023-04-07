#include "ScreenManager.h"
#include "MenuScreens/SetCurrentThresholdScreen/SetCurrentThresholdScreen.h"
#include "MenuScreens/SetTemperatureCurveScreen/SetTemperatureCurveScreen.h"
#include "MenuScreens/SetScreenTimeoutScreen/SetScreenTimeoutScreen.h"

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