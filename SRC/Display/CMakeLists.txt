set(SRC ./Game.cpp)
add_library(DISPLAY ${SRC})

find_package(SFML 2 COMPONENTS system window graphics)
include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(DISPLAY sfml-system sfml-graphics sfml-window)
