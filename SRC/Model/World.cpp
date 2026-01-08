#include "./World.h"
#include "Subjects/Pacman.h"

#include <cmath>

void World::addWall(const std::shared_ptr<Logic::Wall> w) {
    Walls.insert(w);
}

void World::addPacman(const std::shared_ptr<Logic::Pacman> p) {
    Pacman = p;
}

void World::simulate() {
    Pacman->move();
    Pacman->notify();

    for (auto w: Walls) {
        if (Pacman->getDirection() == -1) {
            break;
        }
        std::pair<double, double> Xs = Pacman->getX();
        std::pair<double, double> Ys = Pacman->getY();

        if (Xs.first == Xs.second) {
            std::pair<double, double> coordsWall = w->getCoords();
            
            if (std::abs(Xs.first - coordsWall.first) < 1 and std::abs(Ys.second - coordsWall.second) < 1) {
                if (Ys.first < Ys.second) {
                    Pacman->setPosition(Xs.first, coordsWall.second - 1);
                } else {
                    Pacman->setPosition(Xs.first, coordsWall.second + 1);
                }
                Pacman->clearDirection();
            }
        }

        else if (Ys.first == Ys.second) {
            std::pair<double, double> coordsWall = w->getCoords();
            
            if (std::abs(Xs.second - coordsWall.first) < 1 and std::abs(Ys.first - coordsWall.second) < 1) {
                if (Xs.first < Xs.second) {
                    Pacman->setPosition(coordsWall.first - 1, Ys.first);
                } else {
                    Pacman->setPosition(coordsWall.first + 1, Ys.first);
                }
                Pacman->clearDirection();
            }

        }
    }

    Pacman->notify();
}

bool  World::nextFrame() const {
    return watch->nextFrame();
}
