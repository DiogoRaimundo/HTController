#include "set_temperature_curve_screen.h"

SetTemperatureCurveScreen::SetTemperatureCurveScreen(ScreenManager* screenManager) : ScreenState(screenManager)
{

}

const char* SetTemperatureCurveScreen::getName()
{
	return SetTemperatureCurveScreen::getScreenName();
}

ScreenState* SetTemperatureCurveScreen::triggerAction(UiAction action)
{
	switch (action)
	{
	case UiAction::ScrollRight:
		return screenManager->getScreenTimeoutMenuOption();

	case UiAction::ScrollLeft:
		return screenManager->getAcOnThresholdMenuOption();

	case UiAction::Back:
		break;

	case UiAction::Select:
		break;

	default:
		break;
	}

	return this;
}

const char* SetTemperatureCurveScreen::getScreenName()
{
	return "SetTemperatureCurve";
}