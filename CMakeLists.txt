include(GoogleTest)

cmake_minimum_required (VERSION 3.10.2)
project (github_actions_gtest_example)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -g")


# Sets the compiling options for Khiops
function(set_options target)
  # Show the current target information
  get_target_property(target_type ${target} TYPE)
  message(STATUS "Setting up ${target_type} ${target}")

  # General compiler properties and definitions
  set_property(TARGET ${target} PROPERTY POSITION_INDEPENDENT_CODE TRUE)
  target_compile_definitions(${target} PRIVATE UNICODE _UNICODE)
  target_compile_definitions(${target} PRIVATE $<$<CONFIG:RELEASE,RELWITHDEBINFO>:NOALL>)
  target_compile_definitions(${target} PRIVATE $<$<CONFIG:RELWITHDEBINFO>:__ALPHA__>)

  # Delegate to specialized function for Windows and Unix-like
  if(MSVC)
 
    # Debug only compiling options
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    # Definitions
    target_compile_definitions(${target} PRIVATE _DEBUG _CONSOLE)

    # Options
    #
    # - /RTC1: Enable run-time error checks.
    # - /ZI: Generates "Format Database for 'Edit and Continue'" debug information format.
    # - /MTd: Use multithread debug runtime (set via MSVC_RUNTIME_LIBRARY property).
    #
    target_compile_options(${target} PRIVATE /RTC1 /ZI)
    set_target_properties(${target} PROPERTIES MSVC_RUNTIME_LIBRARY MultiThreadedDebug)

    # Release only compiling options
    elseif(CMAKE_BUILD_TYPE STREQUAL "Release")
    # Options
    #
    # - /GR-: Do not generate runtime information.
    # - /Oi: Generate instrinsic functions.
    # - /Zi: Generates "Format Database" debug information format.
    # - /MT: Use multithread runtime (set via MSVC_RUNTIME_LIBRARY property).
    #
    target_compile_options(${target} PRIVATE /GR- /Oi /Zi)
    set_target_properties(${target} PROPERTIES MSVC_RUNTIME_LIBRARY MultiThreaded)
    else()
    message(ERROR "Unsuported MSVC CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
    endif()

  endif()
endfunction(set_options)
  



set(tool_dest "bin")
set(lib_dest "lib")
set(include_dest "include/${PROJECT_NAME}")

add_subdirectory(src)
#add_subdirectory(test)
