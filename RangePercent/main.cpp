#include <iostream>

int main(int argc, char **argv)
{
    float num, min, max;
    std::cin >> num;
    std::cin >> min;
    std::cin >> max;

    auto res = ((num - min) * 100.f) / (max - min);
    std::cout << "Passing percentage: " << res << "%" << std::endl;
}