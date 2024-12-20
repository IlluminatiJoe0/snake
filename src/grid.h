#pragma once

#include "position.h"

class Grid {
public:
    int width;
    int height;
    int cellSize;
    Grid();
    void init();
    void draw(int offsetX, int offsetY);
    int grid[16][16];

private:

};