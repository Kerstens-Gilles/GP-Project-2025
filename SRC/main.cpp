#include "Logic/World/Stopwatch.h"
#include "Display/Game.h"

#include <iostream>

std::shared_ptr<Logic::Stopwatch> Logic::Stopwatch::watchPtr = nullptr;

int main() {
    std::cout << "STARTED PACMAN" << std::endl;
    std::shared_ptr<Logic::Stopwatch> watch = Logic::Stopwatch::getInstance();

    Display::Game g = Display::Game();

    while (g.windowIsOpen()) {
        if (watch->nextFrame()) {
            g.checkWindowEvents();
        }
    }

    return 0;
}
