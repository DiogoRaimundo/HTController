#pragma once

#include "../screen_state.h"

class SetAcOnThresholdScreen :public ScreenState
{
public:
	SetAcOnThresholdScreen();

	virtual std::string getName() override;
};

