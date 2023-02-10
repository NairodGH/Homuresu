################# CONFIG ##################

cmake_minimum_required(VERSION 3.16)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# Project name
project(SuperCRS LANGUAGES C)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    add_compile_options(-fdiagnostics-color=always)
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    add_compile_options(-fcolor-diagnostics)
endif()

set(GAME_PATH game/)

################## CLIENT ##################

set(CLIENT_EXEC
  SuperCRS
)

set(CLIENT_INC
  ${GAME_PATH}
  ${GAME_PATH}/client/include
)

set(CLIENT_SRC
  ${GAME_PATH}/client
)

set(CMAKE_EXE_LINKER_FLAGS -fexceptions)

add_executable(${CLIENT_EXEC}
  ${CLIENT_SRC}/network/client.c
  ${CLIENT_SRC}/network/get.c
  ${CLIENT_SRC}/network/init.c
  ${CLIENT_SRC}/network/send.c
  ${CLIENT_SRC}/main.c
  ${CLIENT_SRC}/memory.c
)

target_include_directories(${CLIENT_EXEC} PUBLIC
  ${CLIENT_INC}
)

# link with libs
find_package(raylib REQUIRED)
target_link_libraries(${CLIENT_EXEC} PUBLIC raylib)

################## SERVER ##################

set(SERVER_EXEC
  SuperCRS-server
)

set(SERVER_INC
  ${GAME_PATH}
  ${GAME_PATH}/server/include
)

set(SERVER_SRC
  ${GAME_PATH}/server
)

set(CMAKE_EXE_LINKER_FLAGS -fexceptions)

add_executable(${SERVER_EXEC}
  ${SERVER_SRC}/network/action.c
  ${SERVER_SRC}/network/cliclose.c
  ${SERVER_SRC}/network/client.c
  ${SERVER_SRC}/network/connection.c
  ${SERVER_SRC}/network/get.c
  ${SERVER_SRC}/network/init.c
  ${SERVER_SRC}/network/send.c
  ${SERVER_SRC}/network/server.c
  ${SERVER_SRC}/network/utils.c
  ${SERVER_SRC}/main.c
  ${SERVER_SRC}/memory.c
)

target_include_directories(${SERVER_EXEC} PUBLIC
  ${SERVER_INC}
)

# link with libs
find_package(raylib REQUIRED)
target_link_libraries(${SERVER_EXEC} PUBLIC raylib)

################## MISC ##################

add_custom_command(
  TARGET ${CLIENT_EXEC} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_BINARY_DIR}/${CLIENT_EXEC}
    ${CMAKE_CURRENT_BINARY_DIR}/../${CLIENT_EXEC}
)

add_custom_command(
  TARGET ${SERVER_EXEC} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy
    ${CMAKE_CURRENT_BINARY_DIR}/${SERVER_EXEC}
    ${CMAKE_CURRENT_BINARY_DIR}/../${SERVER_EXEC}
)