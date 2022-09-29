#pragma once

#include <caf/typed_actor.hpp>
#include "caf/all.hpp"
#include "Displayable.h"
#include "Duck.h"

CAF_BEGIN_TYPE_ID_BLOCK(duck_msg_types, caf::first_custom_type_id)
	CAF_ADD_ATOM(duck_msg_types, do_duck_behavior)
	CAF_ADD_ATOM(duck_msg_types, display_behavior)
CAF_END_TYPE_ID_BLOCK(duck_msg_types)


