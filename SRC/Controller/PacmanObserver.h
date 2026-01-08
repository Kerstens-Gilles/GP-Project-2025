#ifndef PACMANOBSERVER_H
#define PACMANOBSERVER_H

namespace Controller {
    class Observer {
        public:
            Observer() = default;
            virtual ~Observer() = default;
            virtual void update(const int direction) = 0;
    };
}

#endif