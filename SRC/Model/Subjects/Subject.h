#ifndef MODEL_SUBJECT_H
#define MODEL_SUBJECT_H

#include <utility>
#include <set>
#include <memory>

#include "../Observers/Observer.h"

namespace Logic {
    class Subject {
        public:
            Subject() = delete;
            Subject(double x, double y);
            ~Subject() = default;

            [[ nodiscard ]] std::pair<double, double> getLocation() const;
            void subscribe(std::shared_ptr<Observer> sub);
            void unsubscribe(std::shared_ptr<Observer> sub); // maybe not needed

            virtual void notify() = 0;

        private:
            double x;
            double y;

            std::set<std::shared_ptr<Observer>> subs;
    };
}

#endif