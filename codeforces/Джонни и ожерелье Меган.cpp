#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int N;
vector<int> used, d, p;
vector< vector<pair<int, pair<int, int>>>> self;
vector<vector<pair<int, pair<int, int>>>> graph;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<pair<int, int>> o(n);
	for (auto& i : o) cin >> i.first >> i.second;
	for (int i = 20; i >= 0; --i)
	{
		N = (1 << i);
		graph.resize(N); self.resize(N); d.resize(N); p.resize(N), used.resize(N);
		int megaxor = 0;
		for (int j = 0; j < n; ++j)
		{
			o[j].first %= (1 << i);
			o[j].second %= (1 << i);
			if (o[j].first != o[j].second)
			{
				graph[o[j].first].push_back({ o[j].second, { j * 2 + 1, j * 2 + 2 } });
				graph[o[j].second].push_back({ o[j].first, { j * 2 + 1, j * 2 + 2 } });
			}
			else
				self[o[j].first].push_back({ o[j].second, { j * 2 + 1, j * 2 + 2 } });
			megaxor ^= (o[j].first ^ o[j].second);
		}
		if (megaxor) continue;
		//DFS()
	}

	return 0;
}