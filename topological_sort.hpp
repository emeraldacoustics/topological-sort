#include <queue>
#include <vector>

using namespace std;

vector<int> topological_sort(const vector<vector<int> > & E)
{
	const int n = E.size();

	vector<int> d(n, 0);
	for (int u = 0; u < n; u++)
	{
		for (const auto & v : E[u])
			d[v]++;
	}

	vector<int> ans;
	queue<int> que;
	for (int u = 0; u < n; u++)
	{
		if (d[u] == 0)
			que.push(u);
	}
	for (; !que.empty(); que.pop())
	{
		const int & u = que.front();
		ans.push_back(u);
		for (const auto & v : E[u])
		{
			d[v]--;
			if (d[v] == 0)
				que.push(v);
		}
	}
	return ans;
}
