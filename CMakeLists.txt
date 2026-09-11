# CMakeList.txt : CMake project for SpaceOrcs, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Dependencies
include(FetchContent)


# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("SpaceOrcs")



set(RAYLIB_VERSION 5.5)

FetchContent_Declare(
	raylib
	URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
	FIND_PACKAGE_ARGS ${RAYLIB_VERSION}
)
	
set(BUILD_EXAMPLES OFF CACHE INTERNAL "")

FetchContent_MakeAvailable(raylib)


set(SOURCES
"src/SpaceOrcs.cpp"
"src/Math.h"
)


# Add source to this project's executable.
add_executable (${PROJECT_NAME} ${SOURCES})
include_directories("src")
target_link_libraries(${PROJECT_NAME} raylib)

set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)

make_directory(${CMAKE_CURRENT_BINARY_DIR}/resources)

add_custom_target(copy_resources
    COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_CURRENT_LIST_DIR}/resources ${CMAKE_CURRENT_BINARY_DIR}/resources
)
add_dependencies(${PROJECT_NAME} copy_resources)