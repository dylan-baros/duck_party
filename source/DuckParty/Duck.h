#pragma once

#include <string>

class Duck {
	public:
		virtual ~Duck() = default;
		virtual std::string GetNoiseBehavior() const = 0;
		virtual std::string GetFlyBehavior() const = 0;
};