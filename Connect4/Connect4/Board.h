#pragma once
#include <iostream>
#include <array>
#include <map>

enum class EBoardState
{
	EBS_Empty = 0,
	EBS_Player_One,
	EBS_Player_Two
};

template<int size_x, int size_y>
struct Board
{
	std::array<std::array<EBoardState, size_x>, size_y> grid;

	Board();
	void Reset();
	void PrintBoard() const noexcept;

	inline EBoardState GetLoc(int x, int y) const { return grid[y][x]; }
	inline void SetLocVal(int x, int y, EBoardState value) { grid[y][x] = value; }
};

template<int size_x, int size_y>
Board<size_x, size_y>::Board()
{
	Reset();
}

template<int size_x, int size_y>
void Board<size_x, size_y>::Reset()
{
	for (auto& x : grid)
		for (auto& y : x)
			y = EBoardState::EBS_Empty;
}

template<int size_x, int size_y>
void Board<size_x, size_y>::PrintBoard() const noexcept
{
	for (int y = size_y - 1; y >= 0; y--)
	{
		for (auto& x : grid[y])
			std::cout << x << " ";

		std::cout << '\n';
	}

	for (int i = 0; i < size_x; i++)
		std::cout << i << " ";
}

static std::ostream& operator<<(std::ostream& os, const EBoardState& out)
{
	switch (out)
	{
	default:
	case EBoardState::EBS_Empty:
		os << '*';
		break;
	case EBoardState::EBS_Player_One:
		os << 'X';
		break;
	case EBoardState::EBS_Player_Two:
		os << 'Y';
		break;
	}

	return os;
}