#pragma once

#include "../screen_state.h"

class SetAcOnThresholdScreen :public ScreenState
{
public:
	SetAcOnThresholdScreen();

	virtual const char* getName() override;
};

