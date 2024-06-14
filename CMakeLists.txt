include(GoogleTest)

# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

enable_testing()

cmake_minimum_required (VERSION 3.10.2)
project (github_actions_gtest_example)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -g")


set(tool_dest "bin")
set(lib_dest "lib")
set(include_dest "include/${PROJECT_NAME}")

add_subdirectory(src)
add_subdirectory(test)

gtest_discover_tests(${PROJECT_NAME}.test)
