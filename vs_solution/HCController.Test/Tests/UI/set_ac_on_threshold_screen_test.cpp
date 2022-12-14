#include "../../pch.h"

#include "UI/Screens/screen_state.h"
#include "UI/ui_action.h"

#include "UI/Screens/MenuScreens/SetAcOnThresholdScreen/set_ac_on_threshold_screen.h"
#include "UI/Screens/MenuScreens/SetTemperatureCurveScreen/set_temperature_curve_screen.h"
#include "UI/Screens/MenuScreens/SetScreenTimeoutScreen/set_screen_timeout_screen.h"

namespace HCControllerTests {
	TEST(SetAcOnThresholdScreenTestFixture, CheckName)
	{
		ScreenManager* screenManager = new ScreenManager();
		ScreenState* state = new SetAcOnThresholdScreen(screenManager);

		std::string stateName = state->getName();

		EXPECT_EQ(stateName, SetAcOnThresholdScreen::getScreenName());
	}

	TEST(SetAcOnThresholdScreenTestFixture, CheckScreenOnScrollRight)
	{
		ScreenManager* screenManager = new ScreenManager();
		ScreenState* state = new SetAcOnThresholdScreen(screenManager);

		ScreenState* newState = state->triggerAction(UiAction::ScrollRight);

		std::string stateName = newState->getName();

		EXPECT_EQ(stateName, SetTemperatureCurveScreen::getScreenName());
	}

	TEST(SetAcOnThresholdScreenTestFixture, CheckScreenOnScrollLeft)
	{
		ScreenManager* screenManager = new ScreenManager();
		ScreenState* state = new SetAcOnThresholdScreen(screenManager);

		ScreenState* newState = state->triggerAction(UiAction::ScrollLeft);

		std::string stateName = newState->getName();

		EXPECT_EQ(stateName, SetScreenTimeoutScreen::getScreenName());
	}
}