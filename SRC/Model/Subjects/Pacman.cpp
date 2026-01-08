#include "Pacman.h"
#include "Subject.h"

using namespace Logic;

Pacman::Pacman(const double x, const double y) : Subject(x, y), Controller::Observer(), old_x(x), old_y(y) {}

void Pacman::update(const int directionControl) {
    direction = directionControl;
}

void Pacman::move() {
    double speed = 0.05;
    
    old_x = x;
    old_y = y;

    if (direction == 0) {
        x -= speed;
    } else if (direction == 1) {
        x += speed;
    } else if (direction == 2) {
        y += speed;
    } else if (direction == 3) {
        y -= speed;
    }
}

void Pacman::setPosition(double newX, double newY) {
    x = newX;
    y = newY;
}

void Pacman::clearDirection() {
    direction = -1;
}

int Pacman::getDirection() const {
    return direction;
}

std::pair<double, double> Pacman::getX() const {
    return {old_x, x};
}

std::pair<double, double> Pacman::getY() const {
    return {old_y, y};
}