#ifndef OBSERVER_H
#define OBSERVER_H

namespace Logic {
    class Observer {
        public:
            Observer() = default;
            virtual ~Observer() = default;
            virtual void update(double x, double y, bool eaten) = 0;
        
        private:

    };
}

#endif