#include "WallView.h"
#include "SubjectView.h"

#include <SFML/Graphics/Color.hpp>

using namespace Display;

Wall::Wall(float x, float y, int screenSize) : Subject(x, y, screenSize) {
    sub->setFillColor(sf::Color(0, 0, 200));
};

void Wall::update() {};
