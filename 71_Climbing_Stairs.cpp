#include <vector>

using namespace std;

class Solution {
public:
	int climbStairs_v0(int n) {
		if (n == 2) return 2;
		if (n == 1) return 1;
		return climbStairs_v0(n - 1) + climbStairs_v0(n - 2);
	}

	int climbStairs_v1(int n)
	{
		if (n == 2) return 2;
		if (n == 1) return 1;

		vector<int> fib = { 1, 2 };
		for (int i = 2; i < n; ++i)
		{
			fib.push_back(fib[i - 2] + fib[i - 1]);
		}
		return *(fib.end() - 1);
	}

	int climbStairs_v2(int n)
	{
		int a = 1, b = 1;
		while (n--)
			a = (b += a) - a;
		return a;
	}

	int climbStairs(int n) {
		if (n == 2) return 2;
		if (n == 1) return 1;

		vector<int> fib(n, 1);
		fib[1] = 2;
		for (int i = 2; i < n; ++i)
		{
			fib[i] = fib[i - 1] + fib[i - 2];
		}
		return fib[n - 1];
	}
};