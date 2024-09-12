#ifndef GRID_H
#define GRID_H

#include <vector>
struct Sell 
{
    bool isAlive = false;
    int countOfNeibrs = 0;  //Считает кол-во живых соседей
};


class Grid 
{
    public:
        Grid(int gridCountX, int gridCountY);
        Sell& getSell(int x, int y);
        const Sell& getSell(int x, int y) const;
        void toggleSell(int x, int y);
        void update();
        void clear();
        void randomize();
        int getCountX() const;
        int getCountY() const;
    private:
        int gridCountX, gridCountY;
        std::vector<std::vector<Sell>> cells;
        void countNeighbors();
};

#endif // GRID_H
