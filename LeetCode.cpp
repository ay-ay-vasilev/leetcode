#include "stdc++.h"

using namespace std;

class Solution {
public:
	int findMinPath(int s, int end, vector<vector<int>> adj)
	{
		int n = adj.size();
		vector<int> dist(n, n);
		dist[s] = 0;
		queue<int> q;
		q.push(s);

		while (!q.empty())
		{
			int cur = q.front();
			q.pop();

			for (const auto& neigh : adj[cur])
			{
				if (dist[neigh] > dist[cur] + 1)
				{
					dist[neigh] = dist[cur] + 1;
					q.push(neigh);
				}
			}
		}
		return dist[end];
	}
};

int main()
{
	const auto solution = make_unique<Solution>();

	vector<vector<int>> adj = { {1}, {0, 3}, {3, 4}, {1, 2}, {2} };
	int s = 0;
	int e = 4;

	int result = solution->findMinPath(s, e, adj);

	cout << result;

	return 0;
}