cmake_minimum_required(VERSION 3.14)

project(Tests VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME} test1.cpp)

target_link_libraries(${PROJECT_NAME}
  gtest_main
  indexationLib
)

add_test(NAME test1 COMMAND ${PROJECT_NAME})

add_custom_command(
	TARGET ${PROJECT_NAME}
	COMMENT "Run tests"
	POST_BUILD
	COMMAND ${PROJECT_NAME}
)