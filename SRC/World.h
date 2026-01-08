#ifndef WORLD_H
#define WORLD_H

#include "./Model/Subjects/Subject.h"
#include "./Model/Subjects/Wall.h"

#include <memory>
#include <set>

class World {
    public:
        World() = default;

        void addWall(const std::shared_ptr<Logic::Wall> w);

    private:
        std::set<std::shared_ptr<Logic::Subject>> Walls;
        std::set<std::shared_ptr<Logic::Subject>> coins;
        
        std::shared_ptr<Logic::Subject> Pacman;
};

#endif