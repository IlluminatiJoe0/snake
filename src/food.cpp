#include "food.h"
#include "raylib.h"
#include "colors.h"

Food::Food() {}

void Food::draw(int offsetX, int offsetY) {
    DrawCircleV({(float)(this->position.x * 40 + 20 + offsetX), (float)(this->position.y * 40 + 20 + offsetY)}, 11, DARK_YELLOW);
}
