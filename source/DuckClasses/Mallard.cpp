#include "Mallard.h"

using namespace std;

Mallard::Mallard(string name) :
	name_(name) {}

string Mallard::GetNoiseBehavior() const {
	return name_ + " says Quack Quack!";
}

string Mallard::GetFlyBehavior() const {
	return name_ + " goes Flap Flap!";
}
