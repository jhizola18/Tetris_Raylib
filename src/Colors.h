#pragma once
#include "raylib.h"
#include <vector>

//List of the color that will be stored in a vector it was externed
//so it can access outside this header file
extern const Color DarkGrey;
extern const Color Green;
extern const Color Red;
extern const Color Orange;
extern const Color Yellow;
extern const Color Purple;
extern const Color Cyan;
extern const Color Blue;
extern const Color LightBlue;

//This is the vector where all colors will be stored;
std::vector<Color> getCellColors();