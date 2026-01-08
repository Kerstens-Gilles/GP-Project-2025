#ifndef COIN_VIEW_H
#define COIN_VIEW_H

#include "./SubjectView.h"

namespace Display {
    class Coin : public Subject {
        public:
            Coin() = delete;
            ~Coin() override = default;

            Coin(float x, float y, int screenSize);
    };
}

#endif