#include <caf/actor_system.hpp>
#include <caf/scoped_actor.hpp>
#include <caf/caf_main.hpp>

#include "DuckParty/Duck.h"
#include "DuckParty/DuckActor.h"
#include "DuckParty/DisplayActor.h"
#include "DuckClasses/Mallard.h"
#include "DuckClasses/RoboDuck.h"
#include "DuckClasses/TerminalDisplayer.h"

using namespace std;

void caf_main(caf::actor_system& sys) {
	unique_ptr<Duck> duck1 = make_unique<Mallard>("Howard the Duck");
	unique_ptr<Duck> duck2 = make_unique<Mallard>("Darkwing Duck");
	unique_ptr<Duck> duck3 = make_unique<RoboDuck>(42);

	shared_ptr<Displayable> display = make_shared<TerminalDisplayer>();

	DisplayActor display_actor = sys.spawn<DisplayImpl>(display);
	DuckActor duck_actor1 = sys.spawn<DuckImpl>(move(duck1), 500, display_actor);
	DuckActor duck_actor2 = sys.spawn<DuckImpl>(move(duck2), 1000, display_actor);
	DuckActor duck_actor3 = sys.spawn<DuckImpl>(move(duck3), 1500, display_actor);

	caf::scoped_actor self(sys);
	self->send(display_actor, display_behavior_v, std::chrono::system_clock::now(), "Let's get this party started!");
}

CAF_MAIN(caf::id_block::duck_msg_types)