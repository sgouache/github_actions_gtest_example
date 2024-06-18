# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

include(GoogleTest)

enable_testing()

add_executable(
  hello_test
  hello_test.cc
)
target_include_directories(hello_test
  PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
         ${${PROJECT_NAME}_SOURCE_DIR}/src)
set_options(hello_test)
find_package(GTest CONFIG REQUIRED)

target_link_libraries(
  hello_test
  ${PROJECT_NAME}
  GTest::gtest_main
)

gtest_discover_tests(hello_test)