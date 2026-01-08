#ifndef PACMAN_H
#define PACMAN_H

#include "./Subject.h"

namespace Logic {
    class Pacman : public Subject {
        public:
            Pacman(const double x, const double y);
    };
}

#endif