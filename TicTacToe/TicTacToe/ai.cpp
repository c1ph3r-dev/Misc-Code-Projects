#include "ai.h"
#include <limits>

template <typename T>
T max(T x, T y)
{
	return (x > y) ? x : y;
}

template <typename T>
T min(T x, T y)
{
	return (x < y) ? x : y;
}

struct PlayerWon
{
	bool Player;
	bool Won;

	PlayerWon() = default;
	PlayerWon(bool p, bool w) : Player(p), Won(w) {}
	~PlayerWon() = default;
};

PlayerWon GameWon(std::array<std::array<char, 3>, 3> grid)
{
	if (grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2]) // L2R Diaganol
	{
		if (grid[0][0] = 'x')
			return PlayerWon(false, true);
		
		return PlayerWon(true, true);
	}
	if (grid[0][2] == grid[1][1] && grid[0][2] == grid[2][0]) // R2L Diaganol
	{
		if (grid[0][2] = 'x')
			return PlayerWon(false, true);

		return PlayerWon(true, true);
	}

	for (size_t i = 0; i < 3; i++)
	{
		if (grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2]) // Rows
		{
			if (grid[i][0] = 'x')
				return PlayerWon(false, true);

			return PlayerWon(true, true);
		}

		if (grid[0][i] == grid[1][i] && grid[0][i] == grid[2][i]) // Columns
		{
			if (grid[0][i] = 'x')
				return PlayerWon(false, true);

			return PlayerWon(true, true);
		}
	}

	return PlayerWon(0, false);
}

int TicAI::MiniMax(std::array<std::array<char, 3>, 3> grid, int depth, int alpha, int beta, bool isMaximizing)
{
	auto Won = GameWon(grid);
	if (Won.Won)
		return Won.Player ? 1 : -1;

	int available = 9;
	for (size_t i = 0; i < 3; i++)
		for (size_t j = 0; j < 3; j++)
		{
			if (grid[i][j] == 'x' || grid[i][j] == 'o')
			{
				--available;
			}
			else
				break;
		}
	if (available <= 0)
		return 0;

	if (isMaximizing)
	{
		int maxScore = std::numeric_limits<int>::min();
		for (size_t i = 0; i < 3; i++)
		{
			for (size_t j = 0; j < 3; j++)
			{
				if (grid[i][j] != 'x' && grid[i][j] != 'o')
				{
					grid[i][j] = 'o';
					auto score = MiniMax(grid, depth + 1, alpha, beta, false);
					grid[i][j] = 'p';
					maxScore = max(maxScore, score);
				}
			}
		}
		return maxScore;
	}
	else
	{
		int minScore = std::numeric_limits<int>::max();
		for (size_t i = 0; i < 3; i++)
		{
			for (size_t j = 0; j < 3; j++)
			{
				if (grid[i][j] != 'x' && grid[i][j] != 'o')
				{
					grid[i][j] = 'x';
					auto score = MiniMax(grid, depth + 1, alpha, beta, true);
					grid[i][j] = 'p';
					minScore = min(minScore, score);
					return minScore;
				}
			}
		}
		return minScore;
	}
}

Coordinate TicAI::NextTurn(std::array<std::array<char, 3>, 3> grid)
{
	int bestScore = std::numeric_limits<int>::min();
	constexpr int alpha = std::numeric_limits<int>::min();
	constexpr int beta = std::numeric_limits<int>::max();

	Coordinate bestMove{};
	for (size_t i = 0; i < 3; i++)
		for (size_t j = 0; j < 3; j++)
			if (grid[i][j] != 'x' && grid[i][j] != 'o')
			{
				grid[i][j] = 'o';
				auto score = MiniMax(grid, 0, alpha, beta, false);
				grid[i][j] = 'p';
				if (score > bestScore) 
				{
					bestScore = score;
					bestMove.x = i; bestMove.y = j;
				}
			}

	return bestMove;
}

