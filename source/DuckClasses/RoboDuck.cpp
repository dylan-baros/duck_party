#include "RoboDuck.h"

using namespace std;

RoboDuck::RoboDuck(int serial_number) :
	name_("RoboDuck"),
	serial_number_(serial_number) {}

std::string RoboDuck::GetNoiseBehavior() const {
	return name_ + " " + to_string(serial_number_) + ": says Beep Boop!";
}

std::string RoboDuck::GetFlyBehavior() const {
	return name_ + " " + to_string(serial_number_) + ": goes Clank Clank!";
}