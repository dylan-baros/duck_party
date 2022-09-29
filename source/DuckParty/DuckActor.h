#pragma once
#include <chrono>
#include <caf/typed_event_based_actor.hpp>
#include "CustomMessages.h"

#include "Duck.h"
#include "DisplayActor.h"

using DuckActor = caf::typed_actor<
	caf::result<void>(do_duck_behavior)>;

class DuckState {
	public:
		DuckActor::pointer self_;
		std::unique_ptr<Duck> duck_;
		int milliseconds_;
		DisplayActor display_actor_;

		explicit DuckState(DuckActor::pointer self, std::unique_ptr<Duck> duck, int milliseconds, DisplayActor display_actor) :
			self_(self),
			duck_(std::move(duck)),
			milliseconds_(milliseconds),
			display_actor_(display_actor) {}

		DuckActor::behavior_type make_behavior() {
			self_->send(self_, do_duck_behavior_v);
			return {
			[this](do_duck_behavior) {
				self_->delayed_send(self_, std::chrono::milliseconds(milliseconds_), do_duck_behavior_v);
				std::chrono::time_point<std::chrono::system_clock> quackTime = std::chrono::system_clock::now();
				std::string duck_display = duck_->GetFlyBehavior() + " " + duck_->GetNoiseBehavior();
				self_->send(display_actor_, display_behavior_v, quackTime, duck_display);
				}
			};
		}
};

using DuckImpl = DuckActor::stateful_impl<DuckState>;