#ifndef WALL_VIEW_H
#define WALL_VIEW_H

#include "SubjectView.h"

namespace Display {
    class Wall : public Subject{
        public:
            Wall() = delete;
            ~Wall() = default;

            Wall(float x, float y, int screenSize);

            void update();

        private:

            // observed = wall in LOGIC
    };
}

#endif // WALLVIEW_H