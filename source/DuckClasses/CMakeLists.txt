add_library(duck_classes STATIC
    Mallard.cpp
    RoboDuck.cpp
    TerminalDisplayer.cpp
)
target_include_directories(duck_classes PRIVATE
	${CMAKE_CURRENT_LIST_DIR}/..
)