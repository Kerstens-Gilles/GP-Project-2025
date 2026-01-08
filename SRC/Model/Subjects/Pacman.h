#ifndef PACMAN_H
#define PACMAN_H

#include "./Subject.h"
#include "../../Controller/PacmanObserver.h"

#include <utility>

namespace Logic {
    class Pacman final : public Subject, public Controller::Observer {
        public:
            Pacman(const double x, const double y);

            void update(const int direction) override;

            void move();
            void setPosition(double newX, double newY); //To prevent going through walls
            void clearDirection();
            [[nodiscard]] int getDirection() const;

            [[nodiscard]] std::pair<double, double> getX() const;
            [[nodiscard]] std::pair<double, double> getY() const;

        private:
            double old_x;
            double old_y;
            int direction = -1;
            int new_direction = -1;
    };
}

#endif