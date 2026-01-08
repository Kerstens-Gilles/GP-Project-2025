#ifndef GAME_H
#define GAME_H

#include <memory>
#include <set>


#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>

#include "Subjects/SubjectView.h"

#include "../Controller/PacmanControl.h"

namespace Display {

    class Game {
        public:
            Game();
            Game(const unsigned int width);

            [[nodiscard]] bool windowIsOpen() const;
            void checkWindowEvents();

            void checkController() const;
            void renderFrame();

            void addSub(const std::shared_ptr<Subject> sub);
            void addController(const std::shared_ptr<Controller::Pacman> p);

        private:
            std::unique_ptr<sf::RenderWindow> window;

            std::set<std::shared_ptr<Display::Subject>> subjects;
            std::shared_ptr<Controller::Pacman> pacmanControl;
    };

}

#endif