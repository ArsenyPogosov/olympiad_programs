#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m;
vector<vector<int>> fenv;

void change(int i, int j, int add)
{
	for (; i < n; i |= i + 1)
		for (int jj = j; jj < m; jj |= jj + 1)
			fenv[i][jj] += add;
}

int sum(int i, int j)
{
	int res = 0;
	for (; i >= 0; i = (i & (i + 1)) - 1)
		for (int jj = j; jj >= 0; jj = (jj & (jj + 1)) - 1)
			res += fenv[i][jj];
	return res;
}

int sum(int x1, int y1, int x2, int y2)
{
	return sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int q; cin >> n >> q; m = n;
	vector<vector<int>> grid(n, vector<int>(m));
	fenv.resize(n, vector<int>(m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			char h; cin >> h;
			grid[i][j] = (h == '*');
			change(i, j, grid[i][j]);
		}
	while (q--)
	{
		int reg; cin >> reg;
		if (reg == 1)
		{
			int x, y; cin >> x >> y; --x; --y;
			change(x, y, 1 - grid[x][y] * 2);
			grid[x][y] = 1 - grid[x][y];
		}
		if (reg == 2)
		{
			int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
			cout << sum(x1 - 1, y1 - 1, x2 - 1, y2 - 1) << '\n';
		}
	}

	return 0;
}