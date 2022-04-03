#include "screen_state_machine.h"

ScreenStateMachine::ScreenStateMachine() {

}

std::string ScreenStateMachine::getCurrStateName() {
	return currState->getName();
}
