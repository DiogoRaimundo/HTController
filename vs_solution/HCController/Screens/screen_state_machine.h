#pragma once

#include <string>

#include "screen_state.h"
#include "../UI/ui_action.h"

class ScreenStateMachine
{
private:
	ScreenState* currState;

public:
	ScreenStateMachine();

	void triggerAction(UiAction action);
	std::string getCurrStateName();
};

