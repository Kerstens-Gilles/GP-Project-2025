#include "Game.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>

using namespace Display;

Game::Game() : window(new sf::RenderWindow({800, 600}, "PACMAN")) {}

Game::Game(const unsigned int width, const unsigned int height) : window(new sf::RenderWindow({width, height}, "PACMAN")) {}

bool Game::windowIsOpen() const {
    return window->isOpen();
}

void Game::checkWindowEvents() {
    sf::Event event;
    while (window->pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window->close();
        }
    }
}