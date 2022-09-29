add_executable(helloworld
    helloworld.cpp 
)
MESSAGE(${CAF_SOURCE_DIR}, "CAF SOURCE")

target_include_directories(helloworld PUBLIC
    ${CAF_SOURCE_DIR}/libcaf_core/
    PUBLIC ${CAF_SOURCE_DIR}/libcaf_io/
    PUBLIC ${CAF_SOURCE_DIR}/../caf-build/libcaf_core/
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}/..
    PUBLIC ${CMAKE_CURRENT_LIST_DIR}/
)

target_link_libraries(helloworld
    PRIVATE CAF::internal CAF::core
)

