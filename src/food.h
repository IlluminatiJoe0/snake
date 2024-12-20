#pragma once

#include "position.h"

class Food {
public:
    Food();
    Position position;
    void draw(int offsetX, int offsetY);
};