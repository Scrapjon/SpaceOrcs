# CMakeList.txt : CMake project for SpaceOrcs, include source and define
# project specific logic here.
#

cmake_minimum_required (VERSION 3.10)

if (CMAKE_VERSION VERSION_LESS "3.12")
  set(CMAKE_BUILD_PARALLEL_LEVEL 8) # Arbitrary number
endif()

# Dependencies
include(FetchContent)


# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("SpaceOrcs")



set(RAYLIB_VERSION 6.0)

FetchContent_Declare(
	raylib
	URL https://github.com/raysan5/raylib/archive/refs/tags/${RAYLIB_VERSION}.tar.gz
	FIND_PACKAGE_ARGS ${RAYLIB_VERSION}
)
	
set(BUILD_EXAMPLES OFF CACHE INTERNAL "")

FetchContent_MakeAvailable(raylib)


set(SOURCES

# Common
"src/Main.cpp"
"src/OrcMath.h"
"src/OrcMath.cpp"

# Audio
"src/Audio/AudioEngine.h"
"src/Audio/AudioEngine.cpp"

# Game
"src/Game.h"
"src/Game.cpp"

# Entities
"src/Entities/Entity.h"
"src/Entities/Entity.cpp"
"src/Entities/Ship.h"
"src/Entities/Ship.cpp"
"src/EntityManager.h"
"src/EntityManager.cpp"

# Player
"src/Entities/Player.h"
"src/Entities/Player.cpp"

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