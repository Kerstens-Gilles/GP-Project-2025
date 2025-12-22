#include "./Subject.h"

#include <utility>

using namespace Logic;

Subject::Subject(double x, double y) : x(x), y(y) {}

std::pair<double, double> Subject::getLocation() const {
    return {x, y};
}

void Subject::subscribe(std::shared_ptr<Observer> sub) {
    subs.insert(sub);
}

void Subject::unsubscribe(std::shared_ptr<Observer> sub) {
    subs.erase(sub);
}
