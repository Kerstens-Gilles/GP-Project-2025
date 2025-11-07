add_subdirectory(Logic)
add_subdirectory(Display)

add_executable(${PROJECT_NAME} ./main.cpp)

target_link_libraries(${PROJECT_NAME} LOGIC DISPLAY)