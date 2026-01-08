#include "Logic/Stopwatch.h"

#include "View/Game.h"
#include "View/Subjects/WallView.h"
#include "View/Subjects/PacmanView.h"

#include "Model/World.h"
#include "Model/Subjects/Wall.h"
#include "Model/Subjects/Pacman.h"

#include "Controller/PacmanControl.h"

#include <iostream>
#include <memory>

std::shared_ptr<Logic::Stopwatch> Logic::Stopwatch::watchPtr = nullptr;

int main() {
    int screenSize = 800;
    std::cout << "STARTED PACMAN" << std::endl;

    std::unique_ptr<World> W = std::make_unique<World>(World());
    
    std::unique_ptr<Display::Game> G = std::make_unique<Display::Game>(Display::Game());

    // Create Pacman Logic, View and Controller
    std::shared_ptr<Logic::Pacman> p = std::make_shared<Logic::Pacman>(Logic::Pacman(16, 30));
    std::shared_ptr<Display::Pacman> pDisplay = std::make_shared<Display::Pacman>(Display::Pacman(0, 0, screenSize));
    std::shared_ptr<Controller::Pacman> pControl = std::make_shared<Controller::Pacman>(Controller::Pacman(p));

    p->addSub(pDisplay);
    p->notify();

    W->addPacman(p);
    G->addSub(pDisplay);
    G->addController(pControl);

    for (int i=0; i<33; i++) {
        std::shared_ptr<Logic::Wall> wall = std::make_shared<Logic::Wall>(Logic::Wall(i, 0));
        W->addWall(wall);

        std::shared_ptr<Display::Wall> disp_Wall = std::make_shared<Display::Wall>(Display::Wall(0, 0, screenSize));
        wall->addSub(disp_Wall);
        wall->notify();

        G->addSub(disp_Wall);

        wall = std::make_shared<Logic::Wall>(Logic::Wall(i, 32));
        W->addWall(wall);

        disp_Wall = std::make_shared<Display::Wall>(Display::Wall(0, 0, screenSize));
        wall->addSub(disp_Wall);
        wall->notify();

        G->addSub(disp_Wall);
    }

    for (int i=1; i<32; i++) {
        std::shared_ptr<Logic::Wall> wall = std::make_shared<Logic::Wall>(Logic::Wall(0, i));
        W->addWall(wall);

        std::shared_ptr<Display::Wall> disp_Wall = std::make_shared<Display::Wall>(Display::Wall(0, 0, screenSize));
        wall->addSub(disp_Wall);
        wall->notify();

        G->addSub(disp_Wall);


        wall = std::make_shared<Logic::Wall>(Logic::Wall(32, i));
        W->addWall(wall);

        disp_Wall = std::make_shared<Display::Wall>(Display::Wall(0, 0, screenSize));
        wall->addSub(disp_Wall);
        wall->notify();

        G->addSub(disp_Wall);
    }

    while (G->windowIsOpen()) {
        if (W->nextFrame()) {
            G->checkController();
            W->simulate();

            G->checkWindowEvents();
            G->renderFrame();
        }
    }

    return 0;
}
