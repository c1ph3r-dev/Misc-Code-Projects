#pragma once

#include <ciphers.h>
#include <Enigma/Enigma.h>

#include <fstream>
#include <vector>
#include <cstdlib>

Enigma::Core base_encrypt;
Enigma::Core encrypt;


void Gen_Key(unsigned int x)
{
    const char alphabet[26]{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
    srand(x);

    // Rotor
    {
        int temp1, temp2, temp3 = 0;
        temp1 = (rand() % 5) + 1;
        temp2 = temp1;

        while (temp1 == temp2)
        {
            temp1 = (rand() % 5) + 1;
        }

        temp3 = temp1;

        while (temp1 == temp2 || temp1 == temp3)
        {
            temp1 = (rand() % 5) + 1;
        }

        base_encrypt.GenNewRotorsModules(temp1, temp2, temp3);

    }
    // Vigenere
    {
        int temp = rand() % 26;
        vig.push_back(alphabet[temp]);

        while (rand() % 20 != 9)
        {
            temp = rand() % 26;
            vig.push_back(alphabet[temp]);
        }
    }
    // Pair
    {
        Enigma::s_Pairs* pairs = new Enigma::s_Pairs[13]{};
        std::vector<int> letters;
        letters.push_back(rand() % 26);
        while (letters.size() < 26)
        {
            bool check = false;
            int temp = rand() % 26;
            for (int i = 0; i < letters.size(); i++)
            {
                if (temp == letters[i])
                {
                    check = true;
                    break;
                }
            }
            if (!check)
            {
                letters.push_back(temp);
            }
        }

        for (int i = 0; i < 26; i += 2)
        {
            pairs[i / 2].pair1 = letters[i];
            pairs[i / 2].pair2 = letters[i + 1];
        }

        base_encrypt.GenNewPairModule(pairs);
    }

    encrypt = base_encrypt;
}