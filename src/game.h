#pragma once

#include "grid.h"
#include "snake.h"
#include "food.h"

class Game {
public:
    Grid grid;
    Snake snake;
    Food food;
    Game();
    bool gameOver;
    void draw();
    void update();
    void restart();

private:
    void spawnFood();
    Position getRandomPosition();
    Position findFirstEmptyPosition(Position pos);
    void updateGrid();
    void checkFoodCollision();
    void checkCollision();
    int offsetX;
    int offsetY;
};