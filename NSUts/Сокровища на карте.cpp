//source: 
//status: coding

#include <bits/stdc++.h>
using namespace std;
#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif
#pragma endregion

vector<vector<int>> Map;
vector<int> px, py, pc;
int n, m, q, sx, sy;
vector<list<int>> Graph;

list<pair<int, int>> conn(int vx, int vy)
{
	list<pair<int, int>> res;
	int nx, ny;
	nx = vx - 1; ny = vy;
	if (0 <= nx && nx < n && 0 <= ny && ny < m)
		res.push_back({ nx, ny });
	nx = vx; ny = vy - 1;
	if (0 <= nx && nx < n && 0 <= ny && ny < m)
		res.push_back({ nx, ny });
	nx = vx + 1; ny = vy;
	if (0 <= nx && nx < n && 0 <= ny && ny < m)
		res.push_back({ nx, ny });
	nx = vx; ny = vy + 1;
	if (0 <= nx && nx < n && 0 <= ny && ny < m)
		res.push_back({ nx, ny });
	return res;
}

void DFS(int vx, int vy, int c)
{
	Map[vx][vy] = c;
	for (auto& i : conn(vx, vy))
		if (Map[i.first][i.second] == -1)
			DFS(i.first, i.second, c);
}

vector<int> fire;

void DFS2(int vx, int vy)
{
	if (fire[Map[vx][vy]] == 1)
		return;
	fire[Map[vx][vy]] = 1;
	for (auto& i : conn(vx, vy))
		if (Map[i.first][i.second] >= 0)
			DFS2(i.first, i.second);
}

int main()
{
	cin >> n >> m >> q >> sx >> sy; --sx; --sy;
	Map.resize(n, vector<int>(m));
	px.resize(q);
	py.resize(q);
	pc.resize(q);
	for (auto& i : Map)
		for (auto& j : i)
		{
			char h;
			cin >> h;
			j = h == 'X' ? -2 : -1;
		}
	for (int i = 0; i < q; ++i)
	{
		cin >> px[i] >> py[i] >> pc[i]; --px[i]; --py[i];
		Map[px[i]][py[i]] = i;
	}

	int count = q;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if (Map[i][j] == -1)
				DFS(i, j, count++);
	int best = 0;
	for (int mask = 0; mask < (1 << q); ++mask)
	{
		Graph = vector<list<int>>(count, list<int>{});
		int i = 0, tek = 0;
		list<int> toCheck1, toCheck2;
		int nmask = mask;
		while (nmask > 0)
		{
			if (nmask % 2 == 1)
			{
				toCheck1.push_back(i);
				tek += pc[i];
				vector<int> to_con(4, -2);
				int c = 0;
				for (auto& j : conn(px[i], py[i]))
					to_con[c++] = Map[j.first][j.second];
				for (auto& j : to_con)
					if (j != -2)
					{
						Graph[i].push_back(j);
						Graph[j].push_back(i);
					}
			}
			else
				toCheck2.push_back(i);
			nmask = nmask >> 1;
			++i;
		}
		if (tek > best)
		{
			fire = vector<int>(count, 0);
			DFS2(sx, sy);
			bool flag = true;
			for (auto& i : toCheck1)
				if (fire[i] == 0)
				{
					flag = false;
					break;
				}
			for (auto& i : toCheck2)
				if (fire[i] == 1)
				{
					flag = false;
					break;
				}
			if (flag) best = tek;
		}
	}
	cout << best;

	return 0;
}