add_subdirectory(Model)
add_subdirectory(View)

add_executable(${PROJECT_NAME} ./main.cpp)

target_link_libraries(${PROJECT_NAME} LOGIC View)