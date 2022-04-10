#pragma once

#include "../../screen_state.h"
#include "../../screen_manager.h"

class SetAcOnThresholdScreen : public ScreenState {
public:
	SetAcOnThresholdScreen(ScreenManager* screenManager);

	virtual const char* getName() override;
	virtual ScreenState* triggerAction(UiAction action) override;
};

