#include "stdc++.h"

using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		if (n == 2) return 2;
		if (n == 1) return 1;

		vector<int> fib (n, 1);
		fib[1] = 2;
		for (int i = 2; i < n; ++i)
		{
			fib[i] = fib[i - 1] + fib[i - 2];
		}
		return fib[n - 1];
	}
};

int main()
{
	const auto solution = make_unique<Solution>();
	const auto result = solution->climbStairs(45);

	cout << result;

	return 0;
}