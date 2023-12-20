#include <iostream>

#define NUM_OF_RECURSIONS 10

uint64_t Scramble(uint64_t num, int count = 0)
{
	if (count >= NUM_OF_RECURSIONS)
		return num;

	if (num % 2 != 0)
		num += (num * num);
	num *= (2 * num);
	num += (128 * 4);
	num += 64;
	num /= 2;
	num -= 128;

	num = Scramble(num, ++count);
}

int main(int argc, char** argv)
{
	std::cout << Scramble(1000) << std::endl;
	std::cout << Scramble(2998) << std::endl;
}