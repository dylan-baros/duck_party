#include "TerminalDisplayer.h"

using namespace std::chrono;

void TerminalDisplayer::DisplayBehavior(time_point<system_clock> behavior_time, string behavior) {
		time_t read_time = system_clock::to_time_t(behavior_time);
		string time_string = ctime(&read_time);
		time_string.pop_back();
		cout << time_string << ": " << behavior << endl;
}