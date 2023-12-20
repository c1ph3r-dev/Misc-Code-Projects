#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int shirts, jackets, hoodies, tees, pants, shoes;

	cin >> shirts >> jackets >> hoodies >> tees >> pants >> shoes;

	int result = (pants * shoes * (shirts * tees + shirts + jackets * tees)) + (hoodies * pants * shoes);

	cout << "Number of combinations: " << result << endl;

	return  0;
}