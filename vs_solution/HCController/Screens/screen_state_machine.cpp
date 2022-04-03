#include "screen_state_machine.h"

ScreenStateMachine::ScreenStateMachine() {

}

const char* ScreenStateMachine::getCurrStateName() {
	return currState->getName();
}
