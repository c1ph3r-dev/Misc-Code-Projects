#include "DekkerDouble.h"
#include <float.h>
#include <random>

int main()
{
	std::random_device device;
	std::uniform_real_distribution<double> unif(1.0, 2.0);

	double d1 = unif(device);
	double d2 = unif(device);

	auto dd1 = DekkerDouble::MakeDekkerDouble(d1);
	auto dd2 = DekkerDouble::MakeDekkerDouble(d2);

	auto dd3 = dd1 + dd2;

	std::cout << dd3 << std::endl;
	std::cout << d1 << std::endl;

	return 0;
}