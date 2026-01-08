#ifndef SUBJECT_VIEW_H
#define SUBJECT_VIEW_H

#include "../../Model/Observers/Observer.h"

#include <memory>

#include <SFML/Graphics/RectangleShape.hpp>

namespace Display {
    class Subject : public Logic::Observer {
        public:
            Subject() = delete;
            virtual ~Subject() override = default;

            Subject(float x, float y, int screenSize, const double size = 1);

            [[nodiscard]] std::shared_ptr<sf::RectangleShape> getShape() const;

            void update(double logic_x, double logic_y, bool eaten) override;

            bool isConsumed() const;

        protected:
            std::shared_ptr<sf::RectangleShape> sub;

        private:
            int screenSize;
            bool consumed = false;
    };
}

#endif