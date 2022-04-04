cmake_minimum_required(VERSION 3.14)

project(Indexation VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${PROJECT_NAME} indexation.cpp)

add_subdirectory(indexationLib)
add_subdirectory(testsLib)

target_link_libraries(${PROJECT_NAME} 
	indexationLib
)
if (NOT googletest)
	include(FetchContent)	
	FetchContent_Declare(
		googletest
		URL https://github.com/google/googletest/archive/refs/heads/main.zip
	)
	# For Windows: Prevent overriding the parent project's compiler/linker settings
	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
	FetchContent_MakeAvailable(googletest)
endif()
