#include "Game.h"

Game::Game(int gridCountX, int gridCountY, int windowWidth, int windowHeight, int delay)
    : grid(gridCountX, gridCountY), renderer(windowWidth, windowHeight), isPaused(true), quit(false), delay(delay) {}

void Game::run() {
    Uint32 currentTime;         //Времена для просчёта обновления игры
    Uint32 lastUpdateTime = SDL_GetTicks();

    while (!quit) {
        processInput();
        currentTime = SDL_GetTicks();

        if (!isPaused && (currentTime - lastUpdateTime) >= delay) {
            update();
            lastUpdateTime = currentTime;
        }
        render();
    }
}



void Game::processInput() {
    renderer.handleInput(grid, isPaused, quit);
}

void Game::update() {
    grid.update();
}

void Game::render() {
    renderer.render(grid);
}
