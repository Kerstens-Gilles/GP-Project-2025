#include "Logic/Stopwatch.h"
#include "View/Game.h"
#include "View/Objects/Wall.h"

#include <iostream>
#include <memory>

std::shared_ptr<Logic::Stopwatch> Logic::Stopwatch::watchPtr = nullptr;

int main() {
    std::cout << "STARTED PACMAN" << std::endl;
    std::shared_ptr<Logic::Stopwatch> watch = Logic::Stopwatch::getInstance();

    Display::Game g = Display::Game();

    g.addWall(std::make_shared<Display::Wall>(Display::Wall(0.f, 0.f)));
    g.addWall(std::make_shared<Display::Wall>(Display::Wall(40.f, 0.f)));
    g.addWall(std::make_shared<Display::Wall>(Display::Wall(0.f, 40.f)));
    g.addWall(std::make_shared<Display::Wall>(Display::Wall(80.f, 0.f)));
    g.addWall(std::make_shared<Display::Wall>(Display::Wall(0.f, 80.f)));
    g.addWall(std::make_shared<Display::Wall>(Display::Wall(120.f, 0.f)));
    g.addWall(std::make_shared<Display::Wall>(Display::Wall(0.f, 120.f)));

    while (g.windowIsOpen()) {
        if (watch->nextFrame()) {
            g.checkWindowEvents();
        }
        g.renderFrame();
    }

    return 0;
}
