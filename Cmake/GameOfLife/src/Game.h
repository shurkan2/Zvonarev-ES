#ifndef GAME_H
#define GAME_H

#include "Grid.h"
#include "Renderer.h"

class Game {
public:
    Game(int gridCountX, int gridCountY, int windowWidth, int windowHeight, int delay);
    void run();
private:
    Grid grid;
    Renderer renderer;
    bool isPaused;
    bool quit;
    int delay;
    void processInput();
    void update();
    void render();
};

#endif // GAME_H
