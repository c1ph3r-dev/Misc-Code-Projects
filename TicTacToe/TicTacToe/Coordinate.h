#pragma once
#include <iostream>

struct Coordinate
{
    int x, y;

    Coordinate() = default;
    Coordinate(int X, int Y) : x(X), y(Y) {}
    ~Coordinate() = default;
};
