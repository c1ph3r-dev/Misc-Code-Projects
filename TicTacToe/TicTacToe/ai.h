#pragma once
#include <array>
#include "Coordinate.h"

class TicAI
{
private:
	int MiniMax(std::array<std::array<char, 3>, 3> grid, int depth, int alpha, int beta, bool isMaximizing);
public:
	TicAI() = default;
	~TicAI() = default;

	Coordinate NextTurn(std::array<std::array<char, 3>, 3> grid);
};