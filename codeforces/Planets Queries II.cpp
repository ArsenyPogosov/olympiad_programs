#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m = 18;
vector<vector<int>> nxt;
vector<int> d;

void dDFS(int v)
{
	if (d[v] >= 0) return;
	d[v] = -1;

	if (d[nxt[0][v]] == -1)
		d[v] = 0;
	else
	{
		dDFS(nxt[0][v]);
		d[v] = d[nxt[0][v]] + 1;
	}
}

int move(int v, int dist)
{
	if (dist < 0) return -1;
	for (int i = 0; dist > 0; ++i, dist >>= 1)
		if (dist % 2 == 1)
			v = nxt[i][v];

	return v;
}

int res(int a, int b, bool tryloop = true)
{
	if (move(a, d[a] - d[b]) == b) return d[a] - d[b];
	if (tryloop)
	{
		int ans = res(move(a, d[a] + 1), b, false);
		if (ans >= 0) ans += d[a] + 1;
		return ans;
	}
	return -1;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int q; cin >> n >> q; nxt.resize(m, vector<int>(n)); d.resize(n, -2);
	for (auto& i : nxt[0]) { cin >> i; --i; }
	for (int i = 1; i < m; ++i)
		for (int j = 0; j < n; ++j)
			nxt[i][j] = nxt[i - 1][nxt[i - 1][j]];
	for (int i = 0; i < n; ++i)
		if (d[i] == -2)
			dDFS(i);
	while (q--)
	{
		int a, b; cin >> a >> b;
		cout << res(a - 1, b - 1) << '\n';
	}

	return 0;
}