#include "PacmanView.h"
#include "SubjectView.h"

#include <SFML/Graphics.hpp>

using namespace Display;

Pacman::Pacman(float x, float y, int screenSize) : Subject(x, y, screenSize) {
    sub->setFillColor(sf::Color(200, 200, 0));
};

void Pacman::update() {};

void Pacman::move() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        sub->move(- 40.f / 60, 0.f);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        sub->move(40.f / 60, 0.f);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        sub->move(0.f, 40.f / 60);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        sub->move(0.f, - 40.f / 60);
    }
}