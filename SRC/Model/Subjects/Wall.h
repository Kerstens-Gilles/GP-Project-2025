#ifndef LOGIC_WALL_H
#define LOGIC_WALL_H

#include "./Subject.h"

namespace Logic {
    class Wall : public Subject {
        public:
            Wall() = delete;
            Wall(const double x, const double y);
    };
}

#endif // LOGIC_WALL_H