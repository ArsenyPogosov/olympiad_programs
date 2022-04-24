#include <iostream>
#include <vector>
//#include <queue>
#include <list>
#include <set>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

const int INF = 1000000000;

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<int>> g(n, vector<int>(n, -INF)), bn(n, vector<int>(n, -1));
	for (int i = 0; i < m; ++i)
	{
		int x, y, z;
		cin >> x >> y >> z;
		--x;
		--y;
		if (g[x][y] < z)
		{
			g[x][y] = z;
			bn[x][y] = i;
		}
	}
	vector<int> a(k);
	for (auto& i : a)
	{
		cin >> i;
		--i;
	}
	
	vector<vector<int>> dist(n, vector<int>(n)), p(n, vector<int>(n));
	for (int i = 0; i < n; ++i)
	{
		dist[i][i] = 0;
		p[i][i] = -1;
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			dist[i][j] = g[i][j];
			p[i][j] = i;
		}
	for (int c = 0; c < n; ++c)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				if (dist[i][j] < dist[i][c] + dist[c][j] && dist[i][c] > -INF && dist[c][j] > -INF)
				{
					dist[i][j] = dist[i][c] + dist[c][j];
					p[i][j] = p[c][j];
				}
	for (int i = 0; i < n; ++i)
		if (dist[a[0]][i] > -INF && dist[i][a[k - 1]] > -INF && dist[i][i] > 0)
		{
			cout << "infinitely kind";
			return 0;
		}
	vector<list<int>> ans(k - 1);
	for (int i = 0; i < k - 1; ++i)
	{
		int b = a[i], e = a[i + 1];
		while (b != e)
		{
			int c = p[b][e];
			ans[i].push_front(bn[c][e]);
			e = c;
		}
	}
	int count = 0;
	for (auto& i : ans)
		count += i.size();
	cout << count << '\n';
	for (auto& i : ans)
		for (auto& j : i)
			cout << j + 1 << ' ';

	return 0;
}