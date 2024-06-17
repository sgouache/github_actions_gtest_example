# Fetch googletest from its Git repo
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY "https://github.com/google/googletest.git"
  GIT_TAG "v1.13.0")
# For Windows: Prevent overriding the parent project's compiler/linker settings
#
# - set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# - ** This doesn't work due to a bug ** see below for the workaround
FetchContent_MakeAvailable(googletest)

# Workaround for windows: https://github.com/actions/virtual-environments/issues/5900
if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set_property(TARGET gtest PROPERTY MSVC_RUNTIME_LIBRARY MultiThreaded)
    set_property(TARGET gtest_main PROPERTY MSVC_RUNTIME_LIBRARY MultiThreaded)
else()
    set_property(TARGET gtest PROPERTY MSVC_RUNTIME_LIBRARY MultiThreadedDebug)
    set_property(TARGET gtest_main PROPERTY MSVC_RUNTIME_LIBRARY MultiThreadedDebug)
endif()


include(GoogleTest)

enable_testing()

add_executable(
  hello_test
  hello_test.cc
)
set_options(hello_test)
find_package(GTest CONFIG REQUIRED)

target_link_libraries(
  hello_test
  GTest::gtest_main
)

gtest_discover_tests(hello_test)