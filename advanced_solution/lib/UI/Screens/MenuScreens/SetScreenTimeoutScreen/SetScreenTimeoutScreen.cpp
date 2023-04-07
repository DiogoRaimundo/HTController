#include "SetScreenTimeoutScreen.h"

SetScreenTimeoutScreen::SetScreenTimeoutScreen(ScreenManager* screenManager) : ScreenState(screenManager)
{

}

const char* SetScreenTimeoutScreen::getName()
{
	return SetScreenTimeoutScreen::getScreenName();
}

ScreenState* SetScreenTimeoutScreen::triggerAction(UiAction action)
{
	switch (action)
	{
	case UiAction::ScrollRight:
		return screenManager->getAcOnThresholdMenuOption();

	case UiAction::ScrollLeft:
		return screenManager->getTemperatureCurveMenuOption();

	case UiAction::Back:
		break;

	case UiAction::Select:
		break;

	default:
		break;
	}

	return this;
}

const char* SetScreenTimeoutScreen::getScreenName()
{
	return "SetScreenTimeout";
}