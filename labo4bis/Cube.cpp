#include "Cube.h"
#include <raylib.h>

void Cube::draw() {
    //DrawCube({0.0f, 0.0f, 0.0f}, 1.0f, 1.0f, 1.0f, RED);
    DrawCubeWires({2.5f, 2.5f, 2.5f}, 5.0f, 5.0f, 5.0f, BLACK);
}