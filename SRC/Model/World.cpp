#include "./World.h"
#include "Subjects/Coin.h"
#include "Subjects/Pacman.h"
#include "Subjects/Wall.h"

#include <cmath>
#include <cstdlib>
#include <memory>
#include <utility>

void World::addWall(const std::shared_ptr<Logic::Wall> w) {
    Walls.insert(w);
}

void World::addCoin(const std::shared_ptr<Logic::Coin> c) {
    Coins.insert(c);
}

void World::addPacman(const std::shared_ptr<Logic::Pacman> p) {
    Pacman = p;
}

void WallCollision(std::shared_ptr<Logic::Pacman> P, std::shared_ptr<Logic::Wall> W) {
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

bool CoinCollision(std::shared_ptr<Logic::Pacman> P, std::shared_ptr<Logic::Coin> C) {
    std::pair<double, double> PCoords = P->getCoords();
    std::pair<double, double> CCoords = C->getCoords();

    if (
        PCoords.first < CCoords.first + 0.25  && PCoords.first + 1 > CCoords.first &&
        PCoords.second < CCoords.second + 0.25 && PCoords.second + 1 > CCoords.second
    ) {
        C->Consume();
        C->notify();

        return true;
    }
    return false;
}

void World::simulate() {
    Pacman->move();

    for (auto w: Walls) {
        WallCollision(Pacman, w);
    }

    for (auto it=Coins.begin(); it!=Coins.end(); ) {
        if (CoinCollision(Pacman, (*it))) {
            Coins.erase(it++);
        } else {
            it++;
        }
    }

    Pacman->notify();
}

bool  World::nextFrame() const {
    return watch->nextFrame();
}
