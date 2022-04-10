#include "set_ac_on_threshold_screen.h"

SetAcOnThresholdScreen::SetAcOnThresholdScreen(ScreenManager* screenManager) : ScreenState(screenManager)
{

}

const char* SetAcOnThresholdScreen::getName()
{
	return "SetAcOnThreshold";
}

ScreenState* SetAcOnThresholdScreen::triggerAction(UiAction action)
{
	switch (action)
	{
	case UiAction::ScrollRight:
		return screenManager->getTemperatureCurveMenuOption();

	case UiAction::ScrollLeft:
		return screenManager->getScreenTimeoutMenuOption();

	case UiAction::Back:
		break;

	case UiAction::Select:
		break;

	default:
		break;
	}

	return this;
}