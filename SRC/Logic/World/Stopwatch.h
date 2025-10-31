#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <memory>
#include <chrono>

namespace Logic {
    class Stopwatch {
        public:
            static std::shared_ptr<Stopwatch> getInstance();

            bool nextFrame();

        protected:
            Stopwatch();

        private:
            static std::shared_ptr<Stopwatch> watchPtr;
            std::chrono::time_point<std::chrono::system_clock> previous;
            int fps;


        public:
            Stopwatch(const Stopwatch& watch) = delete;
            void operator=(const Stopwatch& watch) = delete;
    };
}

#endif