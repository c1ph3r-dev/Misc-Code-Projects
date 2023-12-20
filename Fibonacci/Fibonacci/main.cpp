#include <iostream>
#include <map>

uint64_t fib(uint64_t n)
{
	static std::map<uint64_t, uint64_t> memo = {};
	if (memo.contains(n)) return memo[n];
	if (n <= 2) return 1;
	memo[n] = fib(n - 1) + fib(n - 2);
	return memo[n];
}

int main()
{
	std::cout << fib(19) << std::endl;
}