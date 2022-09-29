#pragma once

#include "DuckParty/Duck.h"

class RoboDuck : public Duck {
	public:
		explicit RoboDuck(int serialNumber);
		std::string GetNoiseBehavior() const override;
		std::string GetFlyBehavior() const override;

	private:
		std::string name_;
		int serial_number_;
};

