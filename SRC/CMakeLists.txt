add_subdirectory(Logic)
add_subdirectory(View)
add_subdirectory(Model)
add_subdirectory(Controller)

add_executable(${PROJECT_NAME} ./main.cpp)

target_link_libraries(${PROJECT_NAME} LOGIC Controller View Model)