#ifndef COIN_H
#define COIN_H

#include "Subject.h"

// coins are smaller than walls and pacman

namespace Logic {
    class Coin : public Subject {
        public:
            Coin() = delete;
            Coin(const double x, const double y);
    };
}

#endif