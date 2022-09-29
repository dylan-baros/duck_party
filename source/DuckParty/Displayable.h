#pragma once

#include <chrono>

class Displayable {
	public:
		virtual ~Displayable() = default;
		virtual void DisplayBehavior(std::chrono::time_point<std::chrono::system_clock> behavior_time, std::string behavior) = 0;
};
