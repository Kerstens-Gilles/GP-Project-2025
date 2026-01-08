set(SRC ./Game.cpp ./Subjects/SubjectView.cpp ./Subjects/WallView.cpp ./Subjects/PacmanView.cpp ./Subjects/CoinView.cpp)
add_library(View ${SRC})

find_package(SFML 2 COMPONENTS system window graphics)
include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(View sfml-system sfml-graphics sfml-window)
