#pragma once

#include "../../screen_state.h"
#include "../../screen_manager.h"

class SetTemperatureCurveScreen : public ScreenState {
public:
	SetTemperatureCurveScreen(ScreenManager* screenManager);

	virtual const char* getName() override;
	virtual ScreenState* triggerAction(UiAction action) override;
};

