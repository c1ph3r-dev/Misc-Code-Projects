#pragma once
#include <iostream>
#include <array>
#include "Coordinate.h"


class Game
{
public:
	Game() = default;
	~Game() = default;

    void Play(bool isTwoPlayer = true);

private:
	std::array<std::array<char, 3>, 3> grid;
    int RoundsPlayed;

    void PrintGrid();
    Coordinate GetPlayerInput();
    bool GameWon();
    void GameLoop(bool isTwoPlayer = true);
};
