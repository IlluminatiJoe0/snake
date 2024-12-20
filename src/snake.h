#pragma once

#include "position.h"
#include <vector>

class Snake {
public:
    Snake();
    Position head;
    int length;
    int score;
    std::vector<Position> body;
    void draw(int offsetX, int offsetY);
    void handleInput();
    void update();
    void grow();

private:
    bool movingLeft;
    bool movingRight;
    bool movingUp;
    bool movingDown;
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void move(int x, int y);
    void checkOutOfBounds();
    void updateBody();
    bool lastMoveLeft;
    bool lastMoveRight;
    bool lastMoveUp;
    bool lastMoveDown;
};