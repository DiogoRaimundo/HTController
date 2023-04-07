#pragma once

#pragma once

#include "../../screen_state.h"
#include "../../screen_manager.h"

class SetScreenTimeoutScreen : public ScreenState {
public:
	SetScreenTimeoutScreen(ScreenManager* screenManager);

	virtual const char* getName() override;
	virtual ScreenState* triggerAction(UiAction action) override;

	static const char* getScreenName();
};
