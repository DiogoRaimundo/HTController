#pragma once

#include "../../ScreenState.h"
#include "../../ScreenManager.h"

class SetAcOnThresholdScreen : public ScreenState {
public:
	SetAcOnThresholdScreen(ScreenManager* screenManager);

	virtual const char* getName() override;
	virtual ScreenState* triggerAction(UiAction action) override;

	static const char* getScreenName();
};

