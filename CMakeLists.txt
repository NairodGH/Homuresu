# ############### CONFIG ##################

cmake_minimum_required(VERSION 3.24)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# Project name
project(Homuresu LANGUAGES C VERSION 1.0)

if(UNIX)
    set(CMAKE_CXX_FLAGS "-std=c++20 -Ofast")
else()
    set(CMAKE_CXX_FLAGS "/std:c++20 /Ox /EHsc")
endif()

include(FetchContent)
set(FETCHCONTENT_QUIET OFF)

# ################# FETCH DEPENDENCIES ##################
# FetchContent_Declare(
# raylib
# GIT_REPOSITORY https://github.com/raysan5/raylib/archive/refs/tags/4.2.0.tar.gz
# GIT_TAG master
# GIT_PROGRESS TRUE)
# FetchContent_MakeAvailable(raylib)

# ################# CLIENT ##################
execute_process(
    COMMAND bash -c "make -C lib/blib/"
    OUTPUT_VARIABLE outVar
)

# set executable name
set(CLIENT homuresu)

# set root path
set(CLIENT_ROOT src/client)

# fetch include paths
set(CLIENT_INC
    ${CLIENT_ROOT}/include
)

# fetch source files
set(CLIENT_SRC
    ${CLIENT_ROOT}/main.c
    ${CLIENT_ROOT}/mainLoop.c

    ${CLIENT_ROOT}/init/initBullet.c
    ${CLIENT_ROOT}/init/initCamera.c
    ${CLIENT_ROOT}/init/initWall.c
    ${CLIENT_ROOT}/init/initWindow.c

    ${CLIENT_ROOT}/draw/drawBullet.c
    ${CLIENT_ROOT}/draw/drawObs.c

    ${CLIENT_ROOT}/create/createBullet.c

    ${CLIENT_ROOT}/check/checkCollision.c
)

# set include paths
include_directories(
    include
    ${CLIENT_INC}
    lib/blib/include
)

# set source files (create library/executable)
add_executable(${CLIENT} ${CLIENT_SRC})

# link library/executable with deps
find_package(raylib REQUIRED)
target_link_libraries(${CLIENT} PUBLIC raylib)
set_target_properties(${CLIENT} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR})
set_target_properties(${CLIENT} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR})

# ################# MISC ###################
