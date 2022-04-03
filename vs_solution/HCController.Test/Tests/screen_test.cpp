#include "../pch.h"

#include "Screens/screen_state.h"
#include "Screens/MenuScreens/set_ac_on_threshold_screen.h"

namespace HCControllerTests {
	TEST(ScreenTestFixture, CheckSetAcOnThresholdScreenName)
	{
		ScreenState* stateMachine = new SetAcOnThresholdScreen();

		EXPECT_EQ(stateMachine->getName(), "SetAcOnThreshold");
	}
}