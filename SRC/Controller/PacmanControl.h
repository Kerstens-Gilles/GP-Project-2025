#ifndef PACMANCONTROL_H
#define PACMANCONTROL_H

#include "PacmanObserver.h"
#include <memory>

namespace Controller {
    class Pacman {
        public:
            Pacman() = delete;
            Pacman(std::shared_ptr<Controller::Observer> p);
            void notify() const;

        private:
            std::shared_ptr<Controller::Observer> p;
    };
}

#endif