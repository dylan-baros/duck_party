#pragma once

#include "DuckParty/Duck.h"

class Mallard : public Duck {
	public:
		explicit Mallard(std::string name);
		std::string GetNoiseBehavior() const override;
		std::string GetFlyBehavior() const override;
	private:
		std::string name_;
};

