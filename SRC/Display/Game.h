#ifndef GAME_H
#define GAME_H

#include <memory>

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>

namespace Display {

    class Game {
        public:
            Game();
            Game(const unsigned int width, const unsigned int height);
            ~Game() = default;

            [[nodiscard]] bool windowIsOpen() const;
            void checkWindowEvents();

        private:
            std::unique_ptr<sf::RenderWindow> window;
    };

}

#endif