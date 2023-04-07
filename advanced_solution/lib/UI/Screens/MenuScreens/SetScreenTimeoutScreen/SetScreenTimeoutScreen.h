#pragma once

#pragma once

#include "../../ScreenState.h"
#include "../../ScreenManager.h"

class SetScreenTimeoutScreen : public ScreenState {
public:
	SetScreenTimeoutScreen(ScreenManager* screenManager);

	virtual const char* getName() override;
	virtual ScreenState* triggerAction(UiAction action) override;

	static const char* getScreenName();
};
