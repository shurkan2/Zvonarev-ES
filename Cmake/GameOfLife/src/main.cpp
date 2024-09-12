#include "Game.h"
#include <iostream>

int main(int argc, char* argv[]) {

    int gridCountX = 50;
    int gridCountY = 50;
    int windowWidth = 640;
    int windowHeight = 480;
    int delay = 500;

    try {
        if (argc > 1){
            if (argc >= 5) {
                gridCountX = std::stoi(argv[1]);
                gridCountY = std::stoi(argv[2]);
                windowWidth = std::stoi(argv[3]);
                windowHeight = std::stoi(argv[4]);
            }
            if (argc == 6) {
                delay = std::stoi(argv[5]);
            }
            else{
                std::cerr << "usage: grid size x, grid size y, screen width, screen height, (optional) game speed (ms)" << std::endl;
                return 1;
            }
        }

        Game game(gridCountX, gridCountY, windowWidth, windowHeight, delay);
        game.run();

    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    
    return 0;
}
