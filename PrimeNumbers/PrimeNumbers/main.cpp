#include <iostream>
#include <fstream>

int main()
{
	std::ofstream out;
	out.open("output.txt", std::ios::out);
	out << 2 << std::endl << 3 << std::endl;
	
	for (uint64_t i = 5; i < UINT64_MAX; i += 2)
	{
		std::cout << "Testing " << i << "!" << std::endl;
		bool prime = true;
		for (uint64_t j = 3; j < i; j += 2)
		{
			if (i % j == 0)
			{
				prime = false; break;
			}
		}

		if (prime)
			out << i << std::endl;
	}
	out.close();
	return 0;
}