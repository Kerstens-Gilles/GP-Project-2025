#include "PacmanControl.h"

#include <SFML/Graphics.hpp>

#include <iostream>

using namespace Controller;

Pacman::Pacman(std::shared_ptr<Controller::Observer> p) : p(p) {}

void Pacman::notify() const {
    bool pressed = false;
    int direction = -1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        direction = 0;
        pressed = true;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        direction = 1;
        pressed = true;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        direction = 2;
        pressed = true;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        direction = 3;
        pressed = true;
    }

    if (pressed) {
        p->update(direction);
    }
}