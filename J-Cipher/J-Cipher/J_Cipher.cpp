#include "pch.h"
#include "J_Cipher.h"

void JCIPHER::Generate_Key(unsigned long seed)
{
	std::mt19937 rng(seed);
	{
		std::uniform_int_distribution<std::mt19937::result_type> distRot(1, 5);
		mainEncrypt.SetRotorDataPath("Dependencies/RotorModules");

		// Rotor
		int temp1, temp2, temp3 = 0;
		temp1 = distRot(rng);
		temp2 = temp1;

		while(temp1 == temp2)
		{
			temp1 = distRot(rng);
		}

		temp3 = temp1;

		while (temp1 == temp2 || temp1 == temp3)
		{
			temp1 = distRot(rng);
		}

		mainEncrypt.GenNewRotorsModules(temp1, temp2, temp3);
	}

    // Vigenere
    std::uniform_int_distribution<std::mt19937::result_type> distAlph(1, 26);

    int tempVig = distAlph(rng) - 1;
    Vig.push_back(alphabet[tempVig]);

    while (distAlph(rng) != 9)
    {
        tempVig = distAlph(rng) - 1;
        Vig.push_back(alphabet[tempVig]);
    }

    // Pair

    std::array<Enigma::s_Pairs, 13> pairs;
    std::vector<int> letters;
    letters.push_back(distAlph(rng));
    while (letters.size() < 26)
    {
        bool check = false;
        int pairTemp = distAlph(rng);
        for (int i = 0; i < letters.size(); i++)
        {
            if (pairTemp == letters[i])
            {
                check = true;
                break;
            }
        }
        if (!check)
        {
            letters.push_back(pairTemp);
        }
    }

    for (int i = 0; i < 26; i += 2)
    {
        pairs[i / 2].pair1 = letters[i];
        pairs[i / 2].pair2 = letters[i + 1];
    }

    mainEncrypt.GenNewPairModule(pairs);
    pairs.empty();
    backupEncrypt = mainEncrypt;
}

void JCIPHER::Offset(long long x)
{
    mainEncrypt.OffsetRotor(x);
}

void JCIPHER::Reset()
{
    mainEncrypt = backupEncrypt;
}
