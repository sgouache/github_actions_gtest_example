set(CMAKE_CXX_STANDARD 17)

#set(header_path "${${PROJECT_NAME}_SOURCE_DIR}/include/${PROJECT_NAME}")
#set(header ${header_path}/${PROJECT_NAME}.h)
set(src ${PROJECT_NAME}.cpp)


add_library(${PROJECT_NAME} SHARED ${header} ${src})

set_options(${PROJECT_NAME})

#target_include_directories(${PROJECT_NAME}
#  PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
#         ${${PROJECT_NAME}_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME})
  #pthread)

  
add_executable(${PROJECT_NAME}.info info.cpp)

set_options(${PROJECT_NAME}.info)

#target_include_directories(${PROJECT_NAME}.info
#  PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
#         ${${PROJECT_NAME}_SOURCE_DIR}/include)
target_include_directories(${PROJECT_NAME}.info PUBLIC ${CMAKE_CURRENT_BINARY_DIR})
target_link_libraries(${PROJECT_NAME}.info PRIVATE ${PROJECT_NAME})


# install(TARGETS ${PROJECT_NAME}
# 		LIBRARY DESTINATION "${lib_dest}"
#     ARCHIVE DESTINATION "${lib_dest}"
#     COMPONENT library)
# install(TARGETS ${PROJECT_NAME}.info
# 		RUNTIME DESTINATION "${tool_dest}"
#     COMPONENT library)
# install(FILES ${header} DESTINATION "${include_dest}")
