#include "SubjectView.h"

using namespace Display;

Subject::Subject(float x, float y, int screenSize, const double size) : Logic::Observer(), screenSize(screenSize) {
    sub = std::make_shared<sf::RectangleShape>(sf::Vector2f(size * float(screenSize) / 33, size * float(screenSize) / 33));
    sub->setPosition(x, y);
}

std::shared_ptr<sf::RectangleShape> Subject::getShape() const {
    return sub;
}

void Subject::update(double logic_x, double logic_y, bool eaten) {
    if (eaten) {
        consumed = true;
        return;
    }

    // convert x and y from logic to display
    double x = logic_x / 33 * screenSize;
    double y = logic_y / 33 * screenSize;
    
    sub->setPosition(x, y);
}

bool Subject::isConsumed() const {
    return consumed;
}
