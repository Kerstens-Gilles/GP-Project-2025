#ifndef SUBJECT_H
#define SUBJECT_H

#include "../Observers/Observer.h"

#include <utility>
#include <vector>
#include <memory>

namespace Logic {
    class Subject {
        public:
            Subject() = delete;
            Subject(const double x, const double y);

            [[nodiscard]] std::pair<double, double> getLocation() const;

            void notify() const;

            void addSub(std::shared_ptr<Observer> sub);

        private:
            double x;
            double y;

            bool consumed = false;

            std::vector<std::shared_ptr<Observer>> subscribers;
    };
}

#endif