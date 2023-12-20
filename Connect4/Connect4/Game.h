#pragma once
#ifndef B_H_INCLUDED
#define B_H_INCLUDED

#include "Board.h"

#include <algorithm>
#include <iostream>
#include <string>
namespace GAME
{
	class Connect4
	{

#ifdef ROW_SIZE
		static const int row_size = ROW_SIZE;
#else
		static const int row_size = 8;
#endif // !ROW_SIZE

#ifdef COLUMN_SIZE
		static const int column_size = COLUMN_SIZE;
#else
		static const int column_size = 6;
#endif // !COLUMN_SIZE

		Board<row_size, column_size> m_GameBoard;
		std::array<int, row_size> m_Columns;

		struct Coord2D
		{
			int x, y;
			Coord2D(int X, int Y) : x(X), y(Y) {}
		};

		bool bIsPlayer1;
	public:
		Connect4();
		void Run();

	private:
		inline void SwitchPlayer() { bIsPlayer1 = !bIsPlayer1; }
		int GetPlayerMove() const;

		Coord2D PlayInSlot(const int& slot);
		bool IsGameWon(Coord2D loc) const;
	};

	Connect4::Connect4() : bIsPlayer1(true)
	{
		std::fill(m_Columns.begin(), m_Columns.end(), 0);
	}

	void Connect4::Run()
	{
		while (true)
		{
			m_GameBoard.PrintBoard();
			std::string p = bIsPlayer1 ? "Player 1 " : "Player 2 ";
			std::cout << '\n' << p;
			std::cout << "Enter slot you wish to play in: ";
			auto move = GetPlayerMove();
			auto loc = PlayInSlot(move);
			if (loc.x == -1)
			{
				std::cout << "Invalid Play\n";
				system("pause");
				system("cls");
				continue;
			}
			if (IsGameWon(loc))
			{
				std::cout << '\n' << p << "won the game\n";
				std::cout << "Would you like to continue (Y/n): ";
				char choice;
				std::cin >> choice;
				if (choice == 'y' || choice == 'Y')
				{
					m_GameBoard.Reset();
					std::fill(m_Columns.begin(), m_Columns.end(), 0);
					bIsPlayer1 = true;
					system("cls");
					continue;
				}
				break;
			}
			SwitchPlayer();

			system("cls");
		}
	}

	int Connect4::GetPlayerMove() const
	{
		int move{};
		std::cin >> move;
		return move;
	}

	Connect4::Coord2D Connect4::PlayInSlot(const int& slot)
	{
		if (slot >= row_size || slot < 0) return Connect4::Coord2D(-1, -1);
		if (m_Columns[slot] >= column_size) return Connect4::Coord2D(-1, -1);

		auto state = bIsPlayer1 ? EBoardState::EBS_Player_One : EBoardState::EBS_Player_Two;
		m_GameBoard.SetLocVal(slot, m_Columns[slot], state);

		return Connect4::Coord2D(slot, m_Columns[slot]++);
	}

	bool Connect4::IsGameWon(Coord2D loc) const
	{
		system("cls");
		m_GameBoard.PrintBoard();

		std::array<bool, 8> directions;
		std::fill(directions.begin(), directions.end(), true);

		for (int i = 1; i <= 3; i++)
		{
			// Rows left
			if (!(loc.x - i < 0) && directions[0])
			{
				if (!(m_GameBoard.GetLoc(loc.x, loc.y) == m_GameBoard.GetLoc(loc.x - i, loc.y)))
					directions[0] = false;
			}
			else { directions[0] = false; }

			// Rows right
			if (!(loc.x + i >= row_size) && directions[1])
			{
				if (!(m_GameBoard.GetLoc(loc.x, loc.y) == m_GameBoard.GetLoc(loc.x + i, loc.y)))
					directions[1] = false;
			}
			else { directions[1] = false; }

			// Columns down
			if (!(loc.y - i < 0) && directions[2])
			{
				if (!(m_GameBoard.GetLoc(loc.x, loc.y) == m_GameBoard.GetLoc(loc.x, loc.y - i)))
					directions[2] = false;
			}
			else { directions[2] = false; }

			// Columns up
			if (!(loc.y + i >= column_size) && directions[3])
			{
				if (!(m_GameBoard.GetLoc(loc.x, loc.y) == m_GameBoard.GetLoc(loc.x, loc.y + i)))
					directions[3] = false;
			}
			else { directions[3] = false; }

			// Diaganol Left-Down
			if (!(loc.x - i < 0 || loc.y - i < 0) && directions[4])
			{
				if (!(m_GameBoard.GetLoc(loc.x, loc.y) == m_GameBoard.GetLoc(loc.x - i, loc.y - i)))
					directions[4] = false;
			}
			else { directions[4] = false; }

			// Diaganol Right-Down
			if (!(loc.x + i >= row_size || loc.y - i < 0) && directions[5])
			{
				if (!(m_GameBoard.GetLoc(loc.x, loc.y) == m_GameBoard.GetLoc(loc.x + i, loc.y - i)))
					directions[5] = false;
			}
			else { directions[5] = false; }

			// Diaganol Left-Up
			if (!(loc.x - i < 0 || loc.y + i >= column_size) && directions[6])
			{
				if (!(m_GameBoard.GetLoc(loc.x, loc.y) == m_GameBoard.GetLoc(loc.x - i, loc.y + i)))
					directions[6] = false;
			}
			else { directions[6] = false; }

			// Diaganol Right-Down
			if (!(loc.x + i >= row_size || loc.y + i >= column_size) && directions[7])
			{
				if (!(m_GameBoard.GetLoc(loc.x, loc.y) == m_GameBoard.GetLoc(loc.x + i, loc.y + i)))
					directions[7] = false;
			}
			else { directions[7] = false; }
		}

		for (auto& obj : directions)
			if (obj) return true;

		return false;
	}
}

#endif //B_H_INCLUDED