//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/260495/problem/A
//status: coding

#include <bits/stdc++.h>
using namespace std;
#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("dominoes.in");
ofstream fout("dominoes.out");
#define cin fin
#define cout fout
#endif
#pragma endregion

int n, m;
vector< vector<pair<int, int>>> p;
vector<vector<int>> used;
int T = 0;

vector<vector<int>> Map;

list<pair<int, int>> Graph(pair<int, int> v)
{
	int x = v.first, y = v.second, x1, y1;
	list<pair<int, int>> res;
	
	x1 = x - 1; y1 = y;
	if (0 <= x1 && x1 < n && 0 <= y1 && y1 < m && Map[x1][y1])
		res.push_back({ x1, y1 });

	x1 = x + 1; y1 = y;
	if (0 <= x1 && x1 < n && 0 <= y1 && y1 < m && Map[x1][y1])
		res.push_back({ x1, y1 });

	x1 = x; y1 = y - 1;
	if (0 <= x1 && x1 < n && 0 <= y1 && y1 < m && Map[x1][y1])
		res.push_back({ x1, y1 });

	x1 = x; y1 = y + 1;
	if (0 <= x1 && x1 < n && 0 <= y1 && y1 < m && Map[x1][y1])
		res.push_back({ x1, y1 });

	return res;
}

bool DFS(pair<int, int> v)
{
	if (used[v.first][v.second] == T) return false;
	used[v.first][v.second] = T;
	for (auto& i : Graph(v))
		if (p[i.first][i.second] == pair<int, int>{-1, -1} || DFS(p[i.first][i.second]))
		{
			p[i.first][i.second] = v;
			return true;
		}
	return false;
}

int main()
{
	int a, b;
	cin >> n >> m >> a >> b;
	Map.resize(n, vector<int>(m));
	int c = 0;
	for (auto&i: Map)
		for (auto& j : i)
		{
			char h; cin >> h;
			c += j = (h == '*');
		}

	p.resize(n, vector<pair<int, int>>(m, {-1, -1})); 
	used.resize(n, vector<int>(m, -1));
	for (int i = 0; i < n; ++i)
		for (int j = i % 2; j < m; j += 2)
			if (Map[i][j])
				if (DFS({ i, j }))
					++T;

	int count = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 1 - (i % 2); j < m; j += 2)
			if (Map[i][j])
				if (p[i][j] != pair<int, int>{-1, -1})
					++count;
	cout << min(count * a + (c - count * 2) * b, c * b);

	return 0;
}