#ifndef PACMAN_VIEW_H
#define PACMAN_VIEW_H

#include "SubjectView.h"

namespace Display {
    class Pacman : public Subject{
        public:
            Pacman() = delete;
            ~Pacman() = default;

            Pacman(float x, float y, int screenSize);

            void update();

            void move();

        private:

            // observed = wall in LOGIC
    };
}

#endif // WALLVIEW_H