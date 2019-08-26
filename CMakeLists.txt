cmake_minimum_required(VERSION 3.11)

set (CMAKE_CXX_STANDARD 17)

project(tryingout)

include(FetchContent)

set(FETCHCONTENT_UPDATES_DISCONNECTED ON CACHE BOOL "dont update 3rd party libs" FORCE)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
)

FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

add_library(${PROJECT_NAME} STATIC funcs.hpp funcs.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC .)

add_executable(${PROJECT_NAME}_ut funcs_ut.cpp)
target_link_libraries(${PROJECT_NAME}_ut PRIVATE ${PROJECT_NAME} gtest gmock gmock_main)

if(MSVC)
  target_compile_options(${PROJECT_NAME} PRIVATE /W4 /WX)
else()
  target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic -Werror)
endif()