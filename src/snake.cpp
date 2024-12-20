#include "snake.h"
#include "raylib.h"
#include "colors.h"

Snake::Snake() {
    this->head = Position(8, 8);
    this->length = 1;
    this->score = 25600;
    this->movingLeft = true;
    this->movingRight = false;
    this->movingUp = false;
    this->movingDown = false;
    this->lastMoveDown = false;
    this->lastMoveUp = false;
    this->lastMoveLeft = false;
    this->lastMoveRight = false;
}

void Snake::draw(int offsetX, int offsetY) {
    DrawRectangleRounded({(float)(this->head.x * 40 +1 + offsetX), (float)(this->head.y * 40 +1 + offsetY), 39, 39}, 0.5f, 1.0f, DARK_YELLOW);

    for (Position body : this->body) {
        DrawRectangleRounded({(float)(body.x * 40 +1 + offsetX), (float)(body.y * 40 +1 + offsetY), 39, 39}, 0.5f, 1.0f, DARK_YELLOW);
    }
}

void Snake::handleInput() {
    int key = GetKeyPressed();
    if (key == KEY_LEFT && !this->lastMoveRight) {
        this->movingLeft = true;
        this->movingRight = false;
        this->movingUp = false;
        this->movingDown = false;
    } else if (key == KEY_RIGHT && !this->lastMoveLeft) {
        this->movingLeft = false;
        this->movingRight = true;
        this->movingUp = false;
        this->movingDown = false;
    } else if (key == KEY_UP && !this->lastMoveDown) {
        this->movingLeft = false;
        this->movingRight = false;
        this->movingUp = true;
        this->movingDown = false;
    } else if (key == KEY_DOWN && !this->lastMoveUp) {
        this->movingLeft = false;
        this->movingRight = false;
        this->movingUp = false;
        this->movingDown = true;
    }
}

void Snake::update() {
    if (this->movingLeft) {
        moveLeft();
        this->lastMoveLeft = true;
        this->lastMoveRight = false;
        this->lastMoveUp = false;
        this->lastMoveDown = false;
    } else if (this->movingRight) {
        moveRight();
        this->lastMoveRight = true;
        this->lastMoveLeft = false;
        this->lastMoveUp = false;
        this->lastMoveDown = false;
    } else if (this->movingUp) {
        moveUp();
        this->lastMoveUp = true;
        this->lastMoveLeft = false;
        this->lastMoveRight = false;
        this->lastMoveDown = false;
    } else {
        moveDown();
        this->lastMoveDown = true;
        this->lastMoveLeft = false;
        this->lastMoveRight = false;
        this->lastMoveUp = false;
    }
}

void Snake::moveLeft() {
    move(-1, 0);
}

void Snake::moveRight() {
    move(1, 0);
}

void Snake::moveUp() {
    move(0, -1);
}

void Snake::moveDown() {
    move(0, 1);
}

void Snake::move(int x, int y) {
    updateBody();
    this->head.x += x;
    this->head.y += y;


    checkOutOfBounds();
}

void Snake::checkOutOfBounds() {
    if (head.x > 15) {
        head.x = 0;
    } else if (head.x < 0) {
        head.x = 15;
    } else if (head.y > 15) {
        head.y = 0;
    } else if (head.y < 0) {
        head.y = 15;
    }
}

void Snake::updateBody() {
    this->body.push_back(this->head);
    if (this->body.size() > this->length) {
        this->body.erase(this->body.begin());
    }
}

void Snake::grow() {
    this->length ++;
    this->score += 100;
}
