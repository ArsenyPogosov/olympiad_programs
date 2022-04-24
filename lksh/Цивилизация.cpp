#include <iostream>
#include <vector>
#include <deque>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
#include <string>
using namespace std;

const int INF = 10000000;

int main()
{
	int n, m, a, b, c, d;
	cin >> n >> m >> a >> b >> c >> d;
	--a;
	--b;
	--c;
	--d;
	vector<vector<int>> map(n, vector<int>(m));
	for (auto&i : map)
		for (auto&j : i)
		{
			char h;
			cin >> h;
			if (h == '.') j = 1;
			if (h == 'W') j = 2;
			if (h == '#') j = INF;
		}
	deque<pair<int, int>> q, q1, q2;
	q.push_back({ a, b });
	vector<vector<int>> dist(n, vector<int>(m, INF));
	dist[a][b] = 0;
	vector<vector<bool>> used(n, vector<bool>(m, false));
	vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, { -1, -1 }));
	while (!q.empty())
	{
		int x = q.front().first, y = q.front().second;
		q.pop_front();
		if (used[x][y])
			continue;
		used[x][y] = true;

		for (int i = max(x - 1, 0); i <= min(x + 1, n - 1); ++i)
			for (int j = max(y - 1, 0); j <= min(y + 1, m - 1); ++j)
				if (abs(i - x) + abs(j - y) == 1)
					if (dist[i][j] > dist[x][y] + map[i][j])
					{
						dist[i][j] = dist[x][y] + map[i][j];
						parent[i][j] = { x, y };
						if (map[i][j] == 1)
							q1.push_front({ i, j });
						else
							q2.push_back({ i, j });
					}
		if (q.empty())
		{
			q = q1;
			q1 = q2;
			q2 = {};
		}
		if (q.empty())
		{
			q = q1;
			q1 = q2;
		}
	}
	if (dist[c][d] == INF)
		cout << -1;
	else
	{
		cout << dist[c][d] << '\n';
		pair<int, int> tek = { c, d }, next;
		string path = "";
		while (tek != pair<int, int>{-1, -1})
		{
			next = parent[tek.first][tek.second];
			if (tek.first < next.first)
				path += 'N';
			if (tek.first > next.first)
				path += 'S';
			if (tek.second < next.second)
				path += 'W';
			if (tek.second > next.second)
				path += 'E';
			tek = next;
		}
		reverse(path.begin(), path.end());
		cout << path.substr(2, path.size() - 2);
	}

	return 0;
}