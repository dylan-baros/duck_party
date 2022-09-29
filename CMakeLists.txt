cmake_minimum_required(VERSION 3.24)
include(FetchContent)
set(This DuckParty)
project(${This}
    VERSION 1.0
    LANGUAGES CXX
)




set(CMAKE_CXX_STANDARD 17)
set(DBUILD_SHARED_LIBS OFF)

FetchContent_Declare(
  CAF
  GIT_REPOSITORY https://github.com/actor-framework/actor-framework.git
  GIT_TAG        bfa0f83dd5c9151c263c304300c79161ae8cb595
)

# FetchContent_Declare(
#   googletest
#   GIT_REPOSITORY https://github.com/google/googletest.git
#   GIT_TAG        63907e1bfe6f78806b17d094daf2198ee27aad62
# )


option(BUILD_SHARED_LIBS "Build shared library targets" OFF)
# -- CAF options that are on by default ----------------------------------------

option(CAF_ENABLE_EXAMPLES "Build small programs showcasing CAF features" OFF)
option(CAF_ENABLE_IO_MODULE "Build networking I/O module" ON)
option(CAF_ENABLE_TESTING "Build unit test suites" OFF)
option(CAF_ENABLE_TOOLS "Build utility programs such as caf-run" ON)
option(CAF_ENABLE_EXCEPTIONS "Build CAF with support for exceptions" ON)


FetchContent_MakeAvailable(CAF)

#set(importDir ${CMAKE_CURRENT_LIST_DIR}/build/_deps/)
#set(CAF_ROOT ${importDir}/build)
#find_package(CAF)
#set(importIddsDir ${importDir}/idds-sdk/2.2.0-2022-04-19/build)
#set(importCafDir ${importDir}/build)
#set(importTinyXmlDir ${importDir}/tinyxml2/9.0.0/build/ni-linux-rt-8.8)
#set(importGTestDir ${importDir}/gtest/1.11.0/build/ni-linux-rt-8.8)
#set(importDriversDir ${importDir}/ni-drivers/21.0.0/build/ni-linux-rt-8.8)

# --- Build ---

add_subdirectory(source)
#add_subdirectory(${CAF_SOURCE_DIR})

# --- CPACK ---
#include(GNUInstallDirs)

# set(CPACK_GENERATOR "DEB")
# set(CPACK_PACKAGE_CONTACT "support@ni.com")
# set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "x86_64")
# set(CPACK_DEBIAN_FILE_NAME "ni-idds-inst-node_0.1.0_core2-64.ipk")
# set(CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA "${CMAKE_CURRENT_SOURCE_DIR}/scripts/postinst;${CMAKE_CURRENT_SOURCE_DIR}/scripts/prerm")
# set(CMAKE_INSTALL_LIBDIR "lib64")
# set(CMAKE_INSTALL_RPATH $ORIGIN/../lib/ni-idds-inst-node/)

#set(resourcesDir ${CMAKE_CURRENT_LIST_DIR}/source/InstrumentNode/resources)

# install(FILES
# 	${CMAKE_BINARY_DIR}/source/InstrumentNode/InstrumentNode.out 
# 	${resourcesDir}/InstrumentNode.sh
# 	${importIddsDir}/lib/qos.xml
# 	DESTINATION ${CMAKE_INSTALL_BINDIR}/ni-idds-inst-node
#     PERMISSIONS 
#         OWNER_READ OWNER_EXECUTE
# )

# install(FILES
# 	${importIddsDir}/lib/libdds.so
# 	${importIddsDir}/lib/libdds_cf.so
# 	${importIddsDir}/lib/libdds_qos_provider.so
# 	${importIddsDir}/lib/libdds_xml.so
# 	${importIddsDir}/lib/libidds.so
# 	${importIddsDir}/lib/mds-license.lic
# 	DESTINATION /usr/lib64/ni-idds-inst-node
# )

# install(FILES
# 	${resourcesDir}/start-caf-idds.sh
# 	DESTINATION /etc/init.d
# )

# install(FILES
# 	${resourcesDir}/ni-idds-inst-node.conf
# 	DESTINATION /etc/logrotate.d
# )

# install(DIRECTORY DESTINATION /var/lib/ni-idds-inst-node/log)

message(STATUS "CMAKE_LIBRARY_ARCHITECTURE=${CMAKE_LIBRARY_ARCHITECTURE}")
message(STATUS "CMAKE_INSTALL_LIBDIR=${CMAKE_INSTALL_FULL_LIBDIR}")
message(STATUS "CMAKE_INSTALL_LIBDIR=${CMAKE_INSTALL_SYSCONFDIR}")

include(CPack)