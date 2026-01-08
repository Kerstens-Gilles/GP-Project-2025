#include "./World.h"
#include "Subjects/Pacman.h"
#include "Subjects/Wall.h"

#include <cmath>
#include <memory>

void World::addWall(const std::shared_ptr<Logic::Wall> w) {
    Walls.insert(w);
}

void World::addPacman(const std::shared_ptr<Logic::Pacman> p) {
    Pacman = p;
}

void WallCollision(std::shared_ptr<Logic::Pacman> P, std::shared_ptr<Logic::Wall>W) {
    if (P->getDirection() == -1) {
        return;
    }
    std::pair<double, double> Xs = P->getX();
    std::pair<double, double> Ys = P->getY();

    if (Xs.first == Xs.second) {
        std::pair<double, double> coordsWall = W->getCoords();
        
        if (std::abs(Xs.first - coordsWall.first) < 1 and std::abs(Ys.second - coordsWall.second) < 1) {
            if (Ys.first < Ys.second) {
                P->setPosition(Xs.first, coordsWall.second - 1);
            } else {
                P->setPosition(Xs.first, coordsWall.second + 1);
            }
            P->clearDirection();
        }
    }

    else if (Ys.first == Ys.second) {
        std::pair<double, double> coordsWall = W->getCoords();
        
        if (std::abs(Xs.second - coordsWall.first) < 1 and std::abs(Ys.first - coordsWall.second) < 1) {
            if (Xs.first < Xs.second) {
                P->setPosition(coordsWall.first - 1, Ys.first);
            } else {
                P->setPosition(coordsWall.first + 1, Ys.first);
            }
            P->clearDirection();
        }

    }

    return;
}

void World::simulate() {
    Pacman->move();

    for (auto w: Walls) {
        WallCollision(Pacman, w);
    }

    Pacman->notify();
}

bool  World::nextFrame() const {
    return watch->nextFrame();
}
