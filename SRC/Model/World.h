#ifndef WORLD_H
#define WORLD_H

#include "./Subjects/Wall.h"
#include "./Subjects/Pacman.h"

#include "../Logic/Stopwatch.h"

#include <memory>
#include <set>

class World {
    public:
        World() = default;

        void addWall(const std::shared_ptr<Logic::Wall> w);
        void addPacman(const std::shared_ptr<Logic::Pacman> w);

        void simulate();

        [[nodiscard]] bool nextFrame() const;

    private:
        std::set<std::shared_ptr<Logic::Wall>> Walls;
        
        std::shared_ptr<Logic::Pacman> Pacman;

        std::shared_ptr<Logic::Stopwatch> watch = Logic::Stopwatch::getInstance();
};

#endif