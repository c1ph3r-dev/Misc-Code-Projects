#include "Game.h"
#include "ai.h"

void Game::Play(bool isTwoPlayer)
{
    while (true)
    {
        grid[0][0] = '1';
        grid[0][1] = '2';
        grid[0][2] = '3';
        grid[1][0] = '4';
        grid[1][1] = '5';
        grid[1][2] = '6';
        grid[2][0] = '7';
        grid[2][1] = '8';
        grid[2][2] = '9';
        PrintGrid();
        GameLoop(isTwoPlayer);
        break;
    }
}

void Game::PrintGrid()
{
    system("cls");
    std::cout << " " << grid[0][0] << " | " << grid[0][1] << " | " << grid[0][2] << " \n"
        << "-----------\n"
        << " " << grid[1][0] << " | " << grid[1][1] << " | " << grid[1][2] << " \n"
        << "-----------\n"
        << " " << grid[2][0] << " | " << grid[2][1] << " | " << grid[2][2] << " \n";
}

Coordinate Game::GetPlayerInput()
{
    int selection;
    std::cout << std::endl;
    std::cin >> selection;

    if (selection > 9)
    {
        std::cout << "Please choose from position 1-9!\n";
        return GetPlayerInput();
    }

    int x = --selection / 3;
    int y = selection % 3;

    return Coordinate(x, y);
}

bool Game::GameWon()
{
    if (grid[0][0] == grid[1][1] && grid[0][0] == grid[2][2]) // L2R Diaganol
        return true;
    if (grid[0][2] == grid[1][1] && grid[0][2] == grid[2][0]) // R2L Diaganol
        return true;

    for (size_t i = 0; i < 3; i++)
    {
        if (grid[i][0] == grid[i][1] && grid[i][0] == grid[i][2]) // Rows
            return true;
        if (grid[0][i] == grid[1][i] && grid[0][i] == grid[2][i]) // Columns
            return true;
    }

    return false;
}

void Game::GameLoop(bool isTwoPlayer)
{
    RoundsPlayed = 0;
    if (isTwoPlayer)
    {
        bool player = 0;

        while (true)
        {
            Coordinate selection;
            selection = GetPlayerInput();

            if (grid[selection.x][selection.y] != 'o' && grid[selection.x][selection.y] != 'x')
                grid[selection.x][selection.y] = player ? 'o' : 'x';
            else
            {
                system("cls");
                PrintGrid();
                std::cout << "Position already occupied! Please select different position! ";
                continue;
            }
           
            PrintGrid();

            auto done = GameWon();
            if (done)
            {
                auto won = player ? "o" : "x";
                std::cout << "Player " << won << " wins\n";
                break;
            }

            if (++RoundsPlayed >= 9)
            {
                std::cout << "Draw\n";
                break;
            }

            player = !player;
        }
    }
    else
    {
        bool player = 1;
        TicAI ai{};

        while (true)
        {
            Coordinate selection;
            if (player == 0)
            {
                selection = GetPlayerInput();

                if (grid[selection.x][selection.y] != 'o' && grid[selection.x][selection.y] != 'x')
                    grid[selection.x][selection.y] = player ? 'o' : 'x';
                else
                {
                    system("cls");
                    PrintGrid();
                    std::cout << "Position already occupied! Please select different position! ";
                    continue;
                }

                PrintGrid();

                auto done = GameWon();
                if (done)
                {
                    auto won = player ? "o" : "x";
                    std::cout << "Player " << won << " wins\n";
                    break;
                }

                if (++RoundsPlayed >= 9)
                {
                    std::cout << "Draw\n";
                    break;
                }
            }
            else
            {
                selection = ai.NextTurn(grid);
                grid[selection.x][selection.y] = player ? 'o' : 'x';

                PrintGrid();

                auto done = GameWon();
                if (done)
                {
                    auto won = player ? "o" : "x";
                    std::cout << "Player " << won << " wins\n";
                    break;
                }

                if (++RoundsPlayed >= 9)
                {
                    std::cout << "Draw\n";
                    break;
                }

            }

            player = !player;
        }
    }
}