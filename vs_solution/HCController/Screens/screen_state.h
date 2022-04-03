#pragma once

#include <string>

class ScreenState
{
public:
	ScreenState();

	virtual std::string getName() = 0;
};
