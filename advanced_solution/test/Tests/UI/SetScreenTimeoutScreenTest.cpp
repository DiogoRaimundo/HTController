#include "../lib/UI/Screens/ScreenState.h"
#include "../lib/UI/UiAction.h"

#include "../lib/UI/Screens/MenuScreens/SetCurrentThresholdScreen/SetCurrentThresholdScreen.h"
#include "../lib/UI/Screens/MenuScreens/SetTemperatureCurveScreen/SetTemperatureCurveScreen.h"
#include "../lib/UI/Screens/MenuScreens/SetScreenTimeoutScreen/SetScreenTimeoutScreen.h"

namespace HCControllerTests
{
	TEST(SetScreenTimeoutScreenTestFixture, CheckName)
	{
		ScreenManager *screenManager = new ScreenManager();
		ScreenState *state = new SetScreenTimeoutScreen(screenManager);

		std::string stateName = state->getName();

		EXPECT_EQ(stateName, SetScreenTimeoutScreen::getScreenName());
	}

	TEST(SetScreenTimeoutScreenTestFixture, CheckScreenOnScrollRight)
	{
		ScreenManager *screenManager = new ScreenManager();
		ScreenState *state = new SetScreenTimeoutScreen(screenManager);

		ScreenState *newState = state->triggerAction(UiAction::ScrollRight);

		std::string stateName = newState->getName();

		EXPECT_EQ(stateName, SetAcOnThresholdScreen::getScreenName());
	}

	TEST(SetScreenTimeoutScreenTestFixture, CheckScreenOnScrollLeft)
	{
		ScreenManager *screenManager = new ScreenManager();
		ScreenState *state = new SetScreenTimeoutScreen(screenManager);

		ScreenState *newState = state->triggerAction(UiAction::ScrollLeft);

		std::string stateName = newState->getName();

		EXPECT_EQ(stateName, SetTemperatureCurveScreen::getScreenName());
	}
}