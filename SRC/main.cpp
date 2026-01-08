#include "Logic/Stopwatch.h"
#include "View/Game.h"

#include "View/Subjects/SubjectView.h"
#include "View/Subjects/WallView.h"
#include "View/Subjects/PacmanView.h"

#include "World.h"
#include "Model/Subjects/Subject.h"
#include "Model/Subjects/Wall.h"

#include <iostream>
#include <memory>

std::shared_ptr<Logic::Stopwatch> Logic::Stopwatch::watchPtr = nullptr;

int main() {
    int screenSize = 800;
    std::cout << "STARTED PACMAN" << std::endl;
    std::shared_ptr<Logic::Stopwatch> watch = Logic::Stopwatch::getInstance();

    std::unique_ptr<World> W = std::make_unique<World>(World());
    
    Display::Game G = Display::Game();

    float wSpace = float(screenSize) / 33;

    for (int i=0; i<33; i++) {
        std::shared_ptr<Logic::Wall> wall = std::make_shared<Logic::Wall>(Logic::Wall(i, 0));
        W->addWall(wall);

        std::shared_ptr<Display::Wall> disp_Wall = std::make_shared<Display::Wall>(Display::Wall(0, 0, screenSize));
        wall->addSub(disp_Wall);
        wall->notify();

        G.addSub(disp_Wall);

        wall = std::make_shared<Logic::Wall>(Logic::Wall(i, 32));
        W->addWall(wall);

        disp_Wall = std::make_shared<Display::Wall>(Display::Wall(0, 0, screenSize));
        wall->addSub(disp_Wall);
        wall->notify();

        G.addSub(disp_Wall);
    }

    for (int i=1; i<32; i++) {
        std::shared_ptr<Logic::Wall> wall = std::make_shared<Logic::Wall>(Logic::Wall(0, i));
        W->addWall(wall);

        std::shared_ptr<Display::Wall> disp_Wall = std::make_shared<Display::Wall>(Display::Wall(0, 0, screenSize));
        wall->addSub(disp_Wall);
        wall->notify();

        G.addSub(disp_Wall);


        wall = std::make_shared<Logic::Wall>(Logic::Wall(32, i));
        W->addWall(wall);

        disp_Wall = std::make_shared<Display::Wall>(Display::Wall(0, 0, screenSize));
        wall->addSub(disp_Wall);
        wall->notify();

        G.addSub(disp_Wall);
    }

    while (G.windowIsOpen()) {
        if (watch->nextFrame()) {
            G.checkWindowEvents();
            G.renderFrame();
        }
    }

    return 0;
}
