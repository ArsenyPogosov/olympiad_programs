#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
bool graph[5002][5002]; //Иначе завуалированный ML

vector<char> used;

bool DFS(int v)
{
	used[v] = 1;

	for (int i = 0; i < n; ++i)
		if (graph[v][i] == 1)
			if (used[i] != 2 && (used[i] == 1 || DFS(i)))
				return true;

	used[v] = 2;
	return false;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			graph[i][j] = 0;
	for (int i = 0; i < n - 1; ++i)
		for (int j = i + 1; j < n; ++j)
		{
			char h; cin >> h;
			if (h == 'R')
			{
				graph[i][j] = 1;
			}
			else
			{
				graph[j][i] = 1;
			}
		}

	used.resize(n);
	for (int i = 0; i < n; ++i)
		if (!used[i] && DFS(i))
		{
			cout << "NO\n";
			return 0;
		}
	cout << "YES\n";

	return 0;
}