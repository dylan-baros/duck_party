#pragma once

#include <chrono>
#include <vector>
#include <string>
#include <caf/typed_event_based_actor.hpp>

#include "CustomMessages.h"
#include "Displayable.h"

using DisplayActor = caf::typed_actor<
	caf::result<void>(display_behavior, std::chrono::time_point<std::chrono::system_clock>, std::string)>;

class DisplayState {
	public:
		std::shared_ptr<Displayable> displayable_;
	
		explicit DisplayState(std::shared_ptr<Displayable> displayable) :
			displayable_(displayable) {}

		DisplayActor::behavior_type make_behavior() {
			return {
				[this](display_behavior, std::chrono::time_point<std::chrono::system_clock> quack_time, std::string behavior) {
					displayable_->DisplayBehavior(quack_time, behavior);
				}
			};
		}
};

using DisplayImpl = DisplayActor::stateful_impl<DisplayState>;