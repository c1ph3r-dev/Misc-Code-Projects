#pragma once
#include <string>

inline char SwitchCase(char character)
{
    return character ^ ((unsigned int)1 << 5);
}

int CharToIntClamped(char character)
{
	char toUpper{};
	if((int)character >= 97)
		toUpper = SwitchCase(character);
	else
		toUpper = character;

	return ((int)toUpper) - 64;
}

inline char ClampedIntToChar(int character)
{
	return (char)(character + 64);
}

inline int ClampInt(int n, int val = 26)
{
	while(n > val)
		n -= val;
	return n;
}

std::string Encrypt(std::string raw)
{
	int char1 = CharToIntClamped(raw[0]);
	int char2 = CharToIntClamped(raw[1]);

	std::string result;
	result.resize(raw.size());
	result[0] = ClampedIntToChar(char1);
	result[1] = ClampedIntToChar(char2);

	for (int i = 2; i < raw.length(); i++)
	{
		auto step1 = ClampInt(char1 + char2);
		auto step2 = CharToIntClamped(raw[i]);
		auto step3 = ClampInt(step1 + step2);
		result[i] = ClampedIntToChar(step3);

		char1 = char2;
		char2 = char2 + step2;
	}
	return result;
}