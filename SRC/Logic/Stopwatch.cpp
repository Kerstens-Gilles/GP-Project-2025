#include "Stopwatch.h"
#include <chrono>

using namespace Logic;



std::shared_ptr<Stopwatch> Stopwatch::getInstance() {
    if (watchPtr == nullptr) {
        watchPtr = std::shared_ptr<Stopwatch>(new Stopwatch());
    }

    return watchPtr;
}

bool Stopwatch::nextFrame() {
    auto next = std::chrono::system_clock::now();
    auto duration =  (next - previous);
    auto time = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count(); // hernoem naar delta en slaag time sinds start toe

    if (time >= 1000.0 / fps) {
        previous = next;
        return true;
    }

    return false;
}

Stopwatch::Stopwatch() : previous(std::chrono::system_clock::now()), fps(60) {}
