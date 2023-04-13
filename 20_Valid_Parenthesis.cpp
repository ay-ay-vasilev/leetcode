#include <stack>
#include <string>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		stack<char> stack;
		for (const auto& l : s)
		{
			if (l == '(' || l == '{' || l == '[')
			{
				stack.push(l);
			}
			else
			{
				if (stack.empty())
					return false;
				if
					(
						(l == ')' && stack.top() != '(') ||
						(l == '}' && stack.top() != '{') ||
						(l == ']' && stack.top() != '[')
						)
				{
					return false;
				}
				stack.pop();
			}
		}
		if (!stack.empty())
			return false;
		return true;
	}
};