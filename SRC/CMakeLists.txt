add_subdirectory(Logic)
add_subdirectory(View)
add_subdirectory(Model)

add_executable(${PROJECT_NAME} ./main.cpp ./World.cpp)

target_link_libraries(${PROJECT_NAME} LOGIC View Model)