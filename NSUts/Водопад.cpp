#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<pair<int, int>> run;
	vector<vector<char>> map(n, vector<char>(m));
	for (int i = 0 ; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			cin >> map[i][j];
			if (map[i][j] == 'S')
				run.emplace_back(i, j);
		}
	int count = 0;
	vector<vector<char>> used(n, vector<char>(m));
	for (auto& ttt : run)
	{
		int x = ttt.first, y = ttt.second;
		while (!used[x][y])
		{
			used[x][y] = true;
			if (map[x][y] == '_')
			{
				++count;
				break;
			}
			if (map[x][y] == '\\')
			{
				if (map[x][y + 1] == '/')
				{
					++count;
					used[x][y + 1] = true;
					break;
				}
				++y;
				if (map[x][y] == '_')
				{
					if (used[x][y]) break;
					used[x][y] = true;
					++count;
					break;
				}
				++x;
				continue;
			}
			if (map[x][y] == '/')
			{
				if (map[x][y - 1] == '\\')
				{
					++count;
					used[x][y - 1] = true;
					break;
				}
				--y;
				if (map[x][y] == '_')
				{
					if (used[x][y]) break;
					used[x][y] = true;
					++count;
					break;
				}
				++x;
				continue;
			}
			++x;
		}
	}
	cout << count << '\n';

	return 0;
}