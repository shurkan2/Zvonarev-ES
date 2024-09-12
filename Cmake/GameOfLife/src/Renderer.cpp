#include "Renderer.h"

Renderer::Renderer(int windowWidth, int windowHeight)
    : windowWidth(windowWidth), windowHeight(windowHeight) {
    showGrid = false;
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Game of Life", 100, 100, windowWidth, windowHeight, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Renderer::render(const Grid& grid) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    int gridCountX = grid.getCountX();
    int gridCountY = grid.getCountY();

    // Перерасчёт переменных 
    cellWidth = windowWidth / gridCountX;
    cellHeight = windowHeight / gridCountY;

    gridStartPos =  {
        (windowWidth - gridCountX*cellWidth)/2, 
        (windowHeight - gridCountY*cellHeight)/2
    };

    gridEndPos = {
        gridStartPos.x + gridCountX * cellWidth,
        gridStartPos.y + gridCountY * cellHeight
    };

    {   // Отрисовка живых клеток
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        for (int x = 0; x < gridCountX; x++) {
            for (int y = 0; y < gridCountY; y++) {
                if (grid.getSell(x, y).isAlive) {
                    SDL_Rect rect = { gridStartPos.x + x * cellWidth, gridStartPos.y + y * cellHeight, cellWidth, cellHeight };
                    SDL_RenderFillRect(renderer, &rect);
                }
            }
        }
    }
    

    if (showGrid) { //Зарисовка сетки
        SDL_SetRenderDrawColor(renderer, 127, 232, 197, 255); // Цвет границ (лаймовый)

        for (int x = 0; x <= grid.getCountX(); x++) {// Вертикальные линии
            
            SDL_RenderDrawLine(renderer, 
                gridStartPos.x + x * cellWidth, gridStartPos.y, 
                gridStartPos.x + x * cellWidth, gridEndPos.y
            );
        }

        for (int y = 0; y <= grid.getCountY(); y++) {// Горизонтальные линии
            
            SDL_RenderDrawLine(renderer, 
                gridStartPos.x, gridStartPos.y + y * cellHeight, 
                gridEndPos.x, gridStartPos.y + y * cellHeight
            );
        }
    }

    //Зарисовка остального поля серым
    {
        SDL_SetRenderDrawColor(renderer, 100, 100, 100, 127); // Цвет границ (сероватый)
        std::vector<SDL_Rect> rects; 

        if (gridStartPos.y > 0) {
            rects.push_back({ 0, 0, windowWidth, gridStartPos.y });
        }
        if (gridEndPos.y < windowHeight) {
            rects.push_back({ 0, gridEndPos.y, windowWidth, windowHeight - gridEndPos.y });
        }
        if (gridStartPos.x > 0) {
            rects.push_back({ 0, gridStartPos.y, gridStartPos.x, gridEndPos.y - gridStartPos.y });
        }
        if (gridEndPos.x < windowWidth) {
            rects.push_back({ gridEndPos.x, gridStartPos.y, windowWidth - gridEndPos.x, gridEndPos.y - gridStartPos.y });
        }

        for(const auto& rect:rects)
            SDL_RenderFillRect(renderer, &rect);
    }

    SDL_RenderPresent(renderer);
}

void Renderer::handleInput(Grid& grid, bool& isPaused, bool& quit) {
    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            quit = true;
        } else if (e.type == SDL_MOUSEBUTTONDOWN) {
            int x, y;
            SDL_GetMouseState(&x, &y);
             // Проверяем, находится ли точка мыши внутри активной сетки
            if (x >= gridStartPos.x && x < gridEndPos.x &&
                y >= gridStartPos.y && y < gridEndPos.y) {
                
                int gridX = (x - gridStartPos.x) / cellWidth;
                int gridY = (y - gridStartPos.y) / cellHeight;

                grid.toggleSell(gridX, gridY);
            }
        } else if (e.type == SDL_KEYDOWN) {
            if (e.key.keysym.sym == SDLK_SPACE) {
                isPaused = !isPaused;
            }
            if (e.key.keysym.sym == SDLK_g) {
                showGrid = !showGrid;
            }
            if (e.key.keysym.sym == SDLK_ESCAPE){
                quit = true;
            }
            if (e.key.keysym.sym == SDLK_r){
                grid.randomize();
            }
        }
    }
}
