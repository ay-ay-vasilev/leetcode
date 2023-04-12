#include <vector>

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int left = 0;
		int right = height.size() - 1;
		int maxVolume = min(height[left], height[right]) * (right - left);
		int volume = 0;

		while (left != right)
		{
			if (height[left] < height[right]) ++left;
			else --right;

			volume = min(height[left], height[right]) * (right - left);
			if (maxVolume < volume)
				maxVolume = volume;
		}
		return maxVolume;
	}
};