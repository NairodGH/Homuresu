# ############### CONFIG ##################

# init Cmake
cmake_minimum_required(VERSION 3.24)
project(Homuresu LANGUAGES C VERSION 1.0)

# set flags
if(UNIX)
    set(CMAKE_CXX_FLAGS "-std=c++20 -Ofast")
else()
    set(CMAKE_CXX_FLAGS "/std:c++20 /Ox /EHsc")
endif()

# include fetchcontent
include(FetchContent)
set(FETCHCONTENT_QUIET OFF)

# ################# FETCH DEPENDENCIES ##################
FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/refs/tags/4.2.0.tar.gz
    GIT_PROGRESS TRUE)
FetchContent_MakeAvailable(raylib)

# ################# CLIENT ##################

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
    ${CLIENT_ROOT}/draw/drawCube.c
    ${CLIENT_ROOT}/draw/drawGame.c

    ${CLIENT_ROOT}/manage/manageBullet.c

    ${CLIENT_ROOT}/update/updateKeyboard/updateEnter.c
    ${CLIENT_ROOT}/update/updateBullet.c
    ${CLIENT_ROOT}/update/updateCollision.c
    ${CLIENT_ROOT}/update/updateEvent.c
    ${CLIENT_ROOT}/update/updateGame.c
)

# set include paths
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${CLIENT_INC}
    ${CMAKE_SOURCE_DIR}/lib/blib/include
)

# set source files (create library/executable)
add_executable(${CLIENT} ${CLIENT_SRC})

# link library/executable with deps
target_link_libraries(${CLIENT} PUBLIC raylib)
set_target_properties(${CLIENT} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR})
set_target_properties(${CLIENT} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR})

# ################# SERVER ###################

# set executable name
set(SERVER homureserver)

# set root path
set(SERVER_ROOT src/server)

# fetch include paths
set(SERVER_INC
    ${SERVER_ROOT}/include
)

# fetch source files
set(SERVER_SRC
    ${SERVER_ROOT}/main.c
)

# set include paths
include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${SERVER_INC}
    ${CMAKE_SOURCE_DIR}/lib/blib/include
)

# set source files (create library/executable)
add_executable(${SERVER} ${SERVER_SRC})

# link library/executable with deps
target_link_libraries(${SERVER} PUBLIC raylib)
set_target_properties(${SERVER} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR})
set_target_properties(${SERVER} PROPERTIES RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR})

# ################# MISC ###################

# build blib
execute_process(
    COMMAND bash -c "make -C lib/blib/"
    OUTPUT_VARIABLE outVar
)
