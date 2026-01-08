#include "Subject.h"

using namespace Logic;

Subject::Subject(const double x, const double y) : x(x), y(y){};

void Subject::notify() const {
    for (auto s: subscribers) {
        s->update(x, y, consumed);
    }
}

void Subject::addSub(std::shared_ptr<Observer> sub) {
    subscribers.push_back(sub);
}

std::pair<double, double> Subject::getCoords() const {
    return {x, y};
}

void Subject::Consume() {
    consumed = true;
}
