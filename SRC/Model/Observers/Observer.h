#ifndef OBSERVER_H
#define OBSERVER_H

namespace Logic {
    class Observer {
        public:
            Observer() = default;
            ~Observer() = default;

            virtual void Update() = 0;
        private:
            
    };
}

#endif