#ifndef OBSERVER_H
#define OBSERVER_H

namespace Logic {
    class Observer {
        public:
            virtual void update(double x, double y, bool eaten) = 0;
        
        private:

    };
}

#endif