#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m;
vector<vector<char>> mp;
vector<vector<int>> dist, mdist;
vector<vector<pair<int, int>>> p;

vector<pair<int, int>> steps(int x, int y)
{
	vector<pair<int, int>> res, move{ {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
	for (auto& i : move)
	{
		int nx = x + i.first, ny = y + i.second;
		if (0 <= nx && nx < n && 0 <= ny && ny < m)
			if (mp[nx][ny] != '#')
				if (dist[nx][ny] == -1)
					res.emplace_back(nx, ny);
	}

	return res;
}

bool ans(int i, int j)
{
	if (dist[i][j] == -1 || mdist[i][j] != -1 && dist[i][j] >= mdist[i][j]) return false;

	string res = "";
	pair<int, int> it = make_pair(i, j);
	while (dist[it.first][it.second])
	{
		int x = it.first, y = it.second;
		if (p[x][y] == make_pair(x - 1, y)) res += 'D';
		if (p[x][y] == make_pair(x + 1, y)) res += 'U';
		if (p[x][y] == make_pair(x, y - 1)) res += 'R';
		if (p[x][y] == make_pair(x, y + 1)) res += 'L';
		it = p[x][y];
	}

	reverse(res.begin(), res.end());
	cout << "YES\n" << res.size() << '\n' << res << '\n';
	return true;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	mp.resize(n, vector<char>(m));
	for (auto& i : mp) for (auto& j : i) cin >> j;

	dist.resize(n, vector<int>(m, -1));
	queue<pair<int, int>> Q;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (mp[i][j] == 'M')
			{
				Q.emplace(i, j);
				dist[i][j] = 0;
			}
	while (Q.size())
	{
		int x = Q.front().first, y = Q.front().second; Q.pop();
		for (auto& i : steps(x, y))
		{
			dist[i.first][i.second] = dist[x][y] + 1;
			Q.push(i);
		}
	}
	mdist = dist;

	p.resize(n, vector<pair<int, int>>(m));
	dist.assign(n, vector<int>(m, -1));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (mp[i][j] == 'A')
			{
				Q.emplace(i, j);
				dist[i][j] = 0;
				p[i][j] = make_pair(-1, -1);
				i = j = 1e9;
			}
	while (Q.size())
	{
		int x = Q.front().first, y = Q.front().second; Q.pop();
		for (auto& i : steps(x, y))
		{
			dist[i.first][i.second] = dist[x][y] + 1;
			Q.push(i);
			p[i.first][i.second] = make_pair(x, y);
		}
	}

	for (int i = 0; i < n; ++i)
	{
		if (ans(i, 0)) return 0;
		if (ans(i, m - 1)) return 0;
	}
	for (int i = 0; i < m; ++i)
	{
		if (ans(0, i)) return 0;
		if (ans(n - 1, i)) return 0;
	}
	cout << "NO\n";

	return 0;
}