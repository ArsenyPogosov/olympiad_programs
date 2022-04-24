#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m, xa, ya, xb, yb;
vector<vector<char>> mp, used;

vector<pair<int, int>> steps(int x, int y)
{
	vector<pair<int, int>> res, move{ {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
	for (auto& i : move)
	{
		int nx = x + i.first, ny = y + i.second;
		if ((0 <= nx) && (nx < n) && (0 <= ny) && (ny < m))
			if (mp[nx][ny] != '#')
				if (!used[nx][ny])
					res.emplace_back(nx, ny);
	}

	return res;
}

string res = "";

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	mp.resize(n, vector<char>(m));
	used.resize(n, vector<char>(m));
	for (auto& i : mp) for (auto& j : i) cin >> j;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			if (mp[i][j] == 'A')
			{
				xa = i;
				ya = j;
			}
			if (mp[i][j] == 'B')
			{
				xb = i;
				yb = j;
			}
		}

	queue<pair<int, int>> Q; Q.emplace(xa, ya); 
	vector<vector<pair<int, int>>> p(n, vector<pair<int, int>>(m, make_pair(-1, -1))); 
	p[xa][ya] = make_pair(-1, -1);
	used[xa][ya] = true;
	while(Q.size())
	{
		int xv = Q.front().first, yv = Q.front().second; Q.pop();
		if (xv == xb && yv == yb) break;

		for (auto& i : steps(xv, yv))
		{
			Q.push(i);
			p[i.first][i.second] = make_pair(xv, yv);
			used[i.first][i.second] = true;
		}
	}
	pair<int, int> it = make_pair(xb, yb);
	while (it != make_pair(-1, -1))
	{
		if (p[it.first][it.second] == make_pair(it.first - 1, it.second))
			res += 'D';
		if (p[it.first][it.second] == make_pair(it.first + 1, it.second))
			res += 'U';
		if (p[it.first][it.second] == make_pair(it.first, it.second - 1))
			res += 'R';
		if (p[it.first][it.second] == make_pair(it.first, it.second + 1))
			res += 'L';
		it = p[it.first][it.second];
	}
	reverse(res.begin(), res.end());
	if (res == "")
		cout << "NO\n";
	else
		cout << "YES\n" << res.size() << '\n' << res << '\n';

	return 0;
}