#include "./World.h"

void World::addWall(const std::shared_ptr<Logic::Wall> w) {
    Walls.insert(w);
}