#include "Game.h"
#include <string>

int main(int argc, char** argv)
{
    bool isTwoPlayer = true;

    {
        using namespace std::literals;
        for (size_t i = 0; i < argc; i++)
        {
            if (argv[i] == "-ai"s)
                isTwoPlayer = false;
        }
    }

    Game game{};
    game.Play(!isTwoPlayer);
}