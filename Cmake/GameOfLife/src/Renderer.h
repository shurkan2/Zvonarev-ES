#ifndef RENDERER_H
#define RENDERER_H

#include <SDL.h>
#include "Grid.h"

class Renderer {
public:
    Renderer(int windowWidth, int windowHeight);
    ~Renderer();
    void render(const Grid& grid);
    void handleInput(Grid& grid, bool& isPaused, bool& quit);
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    int windowWidth, windowHeight;
    int cellWidth, cellHeight;
    SDL_Point gridStartPos; //Границы сетки и области игры
    SDL_Point gridEndPos;
    bool showGrid; //Показ сетки понажатию "G"
};

#endif // RENDERER_H
