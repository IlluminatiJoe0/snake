#include "game.h"
#include <random>

Game::Game() {
    this->gameOver = false;
    this->grid = Grid();
    this->snake = Snake();
    this->food = Food();
    this->grid.init();

    this->offsetY = 130-16;
    this->offsetX = 130-16;

    spawnFood();
}

void Game::draw() {
    this->grid.draw(offsetX, offsetY);
    this->snake.draw(offsetX, offsetY);
    this->food.draw(offsetX, offsetY);
}

void Game::update() {
    snake.update();
    updateGrid();
    checkCollision();
    checkFoodCollision();
}

void Game::restart() {
    this->gameOver = false;
    this->grid.init();
    this->snake = Snake();
    this->food = Food();
    spawnFood();
}

void Game::spawnFood() {
    this->food.position = getRandomPosition();
}

Position Game::getRandomPosition() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 15);

    Position pos = Position(distrib(gen), distrib(gen));

    if (grid.grid[pos.x][pos.y] != 0) {
        return getRandomPosition();
    }

    return pos;
}

Position Game::findFirstEmptyPosition(Position pos) {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            if (grid.grid[i][j] == 0) {
                pos.x = i;
                pos.y = j;
                return pos;
            }
        }
    }

    this->gameOver = true;

    return pos;
}

void Game::updateGrid() {
    for (int i = 0; i < 16; i++) {
        for (int j = 0; j < 16; j++) {
            grid.grid[i][j] = 0;
        }
    }

    grid.grid[snake.head.x][snake.head.y] = 1;
    for (int i = 0; i < snake.length; i++) {
        grid.grid[snake.body[i].x][snake.body[i].y] = 1;
    }
}

void Game::checkFoodCollision() {
    if (snake.head.x == food.position.x && snake.head.y == food.position.y) {
        spawnFood();
        snake.grow();
    }
}

void Game::checkCollision() {
    for (int i = 0; i < snake.length; i++) {
        if (snake.head.x == snake.body[i].x && snake.head.y == snake.body[i].y) {
            gameOver = true;
        }
    }
}
