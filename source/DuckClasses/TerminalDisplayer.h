#pragma once

#include <iostream>
#include "../DuckParty/Displayable.h"

using namespace std;

class TerminalDisplayer : public Displayable {
	public:
		void DisplayBehavior(std::chrono::time_point<std::chrono::system_clock> behavior_time, string behavior) override;
};