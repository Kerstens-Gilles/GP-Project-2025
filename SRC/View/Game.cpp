#include "Game.h"
#include "Subjects/SubjectView.h"
#include "Subjects/SubjectView.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>

using namespace Display;

Game::Game() : window(new sf::RenderWindow({800, 800}, "PACMAN")) {}

Game::Game(const unsigned int width) : window(new sf::RenderWindow({width, width}, "PACMAN")) {}

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

void Game::renderFrame() {
    window->clear(sf::Color::Black);

    pacman->move();

    for (auto& s: subjects) {
        std::shared_ptr<sf::RectangleShape> sub = s->getShape();
        window->draw(*sub);
    }

    //window->draw(*(pacman->getShape()));

    window->display();
}

void Game::addSub(const std::shared_ptr<Subject> sub) {
    subjects.insert(sub);
}

void Game::setPacman(const std::shared_ptr<Display::Pacman> p) {
    pacman = p;
}
