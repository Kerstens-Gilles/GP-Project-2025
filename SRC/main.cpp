#include "Logic/World/Stopwatch.h"

#include <iostream>

std::shared_ptr<Logic::Stopwatch> Logic::Stopwatch::watchPtr = nullptr;

int main() {
    std::shared_ptr<Logic::Stopwatch> watch = Logic::Stopwatch::getInstance();

    int i = 0;
    while (i < 60) {
        if (watch->nextFrame()) {
            i++;
            std::cout << i << std::endl;
        }
    }

    return 0;
}