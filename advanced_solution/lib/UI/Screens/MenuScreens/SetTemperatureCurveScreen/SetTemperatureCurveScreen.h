#pragma once

#include "../../ScreenState.h"
#include "../../ScreenManager.h"

class SetTemperatureCurveScreen : public ScreenState {
public:
	SetTemperatureCurveScreen(ScreenManager* screenManager);

	virtual const char* getName() override;
	virtual ScreenState* triggerAction(UiAction action) override;

	static const char* getScreenName();
};

