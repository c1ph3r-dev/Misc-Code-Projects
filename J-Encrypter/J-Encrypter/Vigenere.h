#pragma once

#include <string>
#include <vector>

#ifndef VIGENERE_H_
#define VIGENERE_H_

const std::vector<char> alphabetLC = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

enum class e_Choice
{
	ENCODE, DECODE
};

char Logic(char letter, unsigned short shift, bool encode)
{
	unsigned short val{};

	if (!encode)
	{
		shift = 26 - shift;
		while (shift < 0 || shift > 26)
		{
			if (shift < 0)
			{
				shift = shift * -1;
				shift = 26 - shift;
			}
		}
	}

	for (int y = 0; y < 26; y++)
	{
		if (letter == alphabetLC[y])
		{
			if (y + shift > 25)
			{
				val = (y + shift) - 26;
			}
			else
			{
				val = y + shift;
			}
			break;
		}
	}
	
	return alphabetLC[val];
}

void Vigenere(std::vector<char> inputText, std::vector<char>& output, std::vector<char> shift, e_Choice choice)
{
	bool c{};
	switch (choice)
	{
	default:
		c = true;
		break;
	case e_Choice::ENCODE:
		c = true;
		break;
	case e_Choice::DECODE:
		c = false;
	}

	std::vector<short> shiftNum;

	for (int i = 0; i < shift.size(); i++)
	{
		for (int j = 0; j < 26; j++)
		{
			if (shift[i] == alphabetLC[j])
			{
				shiftNum.push_back(j);
				break;
			}
		}
	}

	unsigned short count{ 0 };
	for (int i = 0; i < inputText.size(); i++)
	{
		output.push_back(Logic(inputText[i], shiftNum[count], c));
		count++;
		if (count == shift.size())
		{
			count = 0;
		}
	}
}

std::string Vigenere(std::string inputText, std::vector<char> shift, e_Choice choice = e_Choice::ENCODE)
{
	std::vector<char> input(inputText.begin(), inputText.end());
	std::vector<char> output;
	Vigenere(input, output, shift, choice);

	std::string out(output.begin(), output.end());
	return out;
}

#endif