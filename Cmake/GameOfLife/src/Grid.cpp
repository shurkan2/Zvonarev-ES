#include "Grid.h"

#include <random>    // For generating random numbers
#include <ctime>     // For initializing the random number generator

// genetate random number
int getRandomNumber(int min, int max) 
{
    static std::mt19937 mt(static_cast<unsigned int>(time(0)));
    std::uniform_int_distribution<int> dist(min, max);
    return dist(mt);
}

Grid::Grid(int gridCountX, int gridCountY) : gridCountX(gridCountX), gridCountY(gridCountY), cells(gridCountX, std::vector<Sell>(gridCountY)) {}

Sell& Grid::getSell(int x, int y) {
    return cells[x][y];
}

const Sell& Grid::getSell(int x, int y) const {
    return cells[x][y];
}

void Grid::toggleSell(int x, int y) {
    cells[x][y].isAlive = !cells[x][y].isAlive;
}

void Grid::update() {
    countNeighbors();

    for (int x = 0; x < gridCountX; x++) {
        for (int y = 0; y < gridCountY; y++) {
            if (cells[x][y].isAlive) {
                if (cells[x][y].countOfNeibrs < 2 || cells[x][y].countOfNeibrs > 3) {
                    cells[x][y].isAlive = false;
                }
            } else {
                if (cells[x][y].countOfNeibrs == 3) {
                    cells[x][y].isAlive = true;
                }
            }
        }
    }
}

void Grid::clear() {
    for (int x = 0; x < gridCountX; x++) {
        for (int y = 0; y < gridCountY; y++) {
            cells[x][y].isAlive = false;
            cells[x][y].countOfNeibrs = 0;
        }
    }
}

void Grid::randomize() { 
    clear();
    for (int x = 0; x < gridCountX; x++) {
        for (int y = 0; y < gridCountY; y++) {
            cells[x][y].isAlive = getRandomNumber(0,1);
        }
    }
    countNeighbors();
}

int Grid::getCountX() const {
    return gridCountX;
}

int Grid::getCountY() const {
    return gridCountY;
}

void Grid::countNeighbors() { //Считаем кол-во соседей клетки
    for (int x = 0; x < gridCountX; x++) {
        for (int y = 0; y < gridCountY; y++) {
            cells[x][y].countOfNeibrs = 0;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (i == 0 && j == 0) continue;
                    int nx = x + i;
                    int ny = y + j;
                    if (nx >= 0 && ny >= 0 && nx < gridCountX && ny < gridCountY && cells[nx][ny].isAlive) {
                        cells[x][y].countOfNeibrs++;
                    }
                }
            }
        }
    }
}


