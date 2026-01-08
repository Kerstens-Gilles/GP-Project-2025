#ifndef GAME_H
#define GAME_H

#include <memory>
#include <set>


#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>

#include "Subjects/SubjectView.h"
#include "Subjects/PacmanView.h"

namespace Display {

    class Game {
        public:
            Game();
            Game(const unsigned int width);
            ~Game() = default;

            [[nodiscard]] bool windowIsOpen() const;
            void checkWindowEvents();
            void renderFrame();

            void addSub(const std::shared_ptr<Subject> sub);
            void setPacman(const std::shared_ptr<Display::Pacman> p);

        private:
            std::unique_ptr<sf::RenderWindow> window;

            std::set<std::shared_ptr<Display::Subject>> subjects;
            std::shared_ptr<Display::Pacman> pacman;
    };

}

#endif