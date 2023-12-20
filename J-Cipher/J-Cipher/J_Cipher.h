#pragma once
#include <Enigma.h>
#include <vector>

class JCIPHER
{
	const char alphabet[26]{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
	ENIGMA_MACHINE mainEncrypt;
	ENIGMA_MACHINE backupEncrypt;
	std::vector<char> Vig;

public:
	void Generate_Key(unsigned long seed);
	void Offset(long long x);
	void Reset();
};