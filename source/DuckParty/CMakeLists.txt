add_executable(DuckParty
    main.cpp
    Displayable.h
    DisplayActor.h
    Duck.h
    DuckActor.h 
)

target_include_directories(DuckParty 
    PRIVATE ${CAF_SOURCE_DIR}/libcaf_core/
    PRIVATE ${CAF_SOURCE_DIR}/libcaf_core/mixin/
    PRIVATE ${CAF_SOURCE_DIR}/libcaf_io/
    PRIVATE ${CAF_SOURCE_DIR}/../caf-build/libcaf_core/
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}/..
    PRIVATE ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(DuckParty
    PRIVATE CAF::internal CAF::core duck_classes pthread
)


