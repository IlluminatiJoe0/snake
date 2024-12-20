#include "grid.h"
#include "raylib.h"
#include "colors.h"

Grid::Grid() {
    this->cellSize = 40;
    this->height = 16;
    this->width = 16;
}

void Grid::init() {
    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            this->grid[i][j] = 0;
        }
    }
}

void Grid::draw(int offsetX, int offsetY) {
    for (int i = 0; i < this->height; i++) {
        for (int j = 0; j < this->width; j++) {
            DrawRectangleRoundedLinesEx({j * (float)cellSize + 1 + offsetX, i * (float)cellSize + 1 + offsetY, (float)cellSize - 1, (float)cellSize - 1}, 0.6f, 1.0f, 2.0f, DARK_YELLOW);
        }
    }
}
