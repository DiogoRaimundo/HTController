#pragma once

#include "../UiAction.h"

class ScreenManager;

class ScreenState {
protected:
	ScreenManager* screenManager;

public:
	ScreenState(ScreenManager* a);

	virtual const char* getName() = 0;
	virtual ScreenState* triggerAction(UiAction action) = 0;
};
