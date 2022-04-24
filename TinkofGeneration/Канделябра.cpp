#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const int k = 't' - 'a' + 2, N = 5 * 1e4;

int res = -1;

int n;
vector<int> a;
vector<vector<int>> graph;

int dn[N][k * k][2];

void add(int x, int y, int val)
{
	dn[x][y][1] = max(dn[x][y][1], val);
	if (dn[x][y][0] < dn[x][y][1])
		swap(dn[x][y][0], dn[x][y][1]);
}

int get(int x, int y, int val)
{
	return (dn[x][y][0] != val ? dn[x][y][0] : dn[x][y][1]);
}

void dfsdn(int v, int p = -1)
{
	add(v, 0, 0);
	add(v, 0, 0);
	add(v, a[v], 1);
	add(v, a[v], 1);

	for (auto& i : graph[v])
		if (i != p)
		{
			dfsdn(i, v);
			vector<int> hlp(k * k);
			for (int j = 0; j < k * k; ++j)
			{
				int f = j % k, s = j / k;

				hlp[j] = max(hlp[j], dn[i][j][0]);

				if (a[v] != f && a[v] != s)
					hlp[a[v] + f * k] = max(hlp[a[v] + f * k], dn[i][j][0] + 1);
			}

			for (int j = 0; j < k * k; ++j)
				add(v, j, hlp[j]);
		}

	for (auto& i : dn[v])
		res = max(res, i[0]);
}

void dfsup(int v, int p = -1)
{
	for (auto& i : graph[v])
		if (i != p)
		{
			vector<int> hlp(k * k);
			for (int j = 0; j < k * k; ++j)
			{
				int f = j % k, s = j / k;

				hlp[j] = max(hlp[j], dn[i][j][0]);

				if (a[v] != f && a[v] != s)
					hlp[a[v] + f * k] = max(hlp[a[v] + f * k], dn[i][j][0] + 1);
			}

			for (int j = 0; j < k * k; ++j)
			{
				int f = j % k, s = j / k;

				add(i, j, get(v, j, hlp[j]));

				if (a[i] != f && a[i] != s)
					add(i, a[i] + f * k, get(v, j, hlp[j]) + 1);
			}

			for (auto& j : dn[i])
				res = max(res, j[0]);

			dfsup(i, v);
		}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;

	//if (n > 1000)
	//	k = 'j' - 'a' + 2;

	graph.resize(n);
	for (int i = 0; i < n - 1; ++i)
	{
		int x, y; cin >> x >> y; --x; --y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	a.resize(n);
	for (auto& i : a)
	{
		char h; cin >> h;
		i = (h - 'a') + 1;
	}

	dfsdn(0);
	dfsup(0);

	cout << res << '\n';

	return 0;
}