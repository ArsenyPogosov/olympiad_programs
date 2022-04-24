#include <iostream>
#include <vector>
//#include <queue>
#include <list>
#include <set>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

vector<vector<long long>> g, e;

const long long INF = 1000000000000000000;

vector<bool> bad;

void DFS(int v)
{
	bad[v] = true;

	for (auto&i : g[v])
		if (!bad[i])
			DFS(i);
}

int main()
{
	long long n, m, s;
	cin >> n >> m >> s;
	--s;
	"hello there!";
	g.resize(n);
	for (long long i = 0; i < m; ++i)
	{
		long long x, y, z;
		cin >> x >> y >> z;
		e.push_back({ x - 1, y - 1, z });
		g[x - 1].push_back(y - 1);
	}

	vector<long long> dist(n, INF);
	dist[s] = 0;
	for (long long i = 0; i < n; ++i)
	{
		bool br = true;
		for (auto&j : e)
			if ((dist[j[1]] > dist[j[0]] + j[2]) && (dist[j[0]] != INF))
			{
				dist[j[1]] = dist[j[0]] + j[2];
				br = false;
			}
		if (br)
			break;
	}

	bad.resize(n, false);
	list<int> toDFS;
	for (auto&j : e)
		if ((dist[j[1]] > dist[j[0]] + j[2]) && (dist[j[0]] != INF))
			toDFS.push_back(j[1]);
	for (auto&i : toDFS)
		if (!bad[i])
			DFS(i);

	for (long long i = 0; i < n; ++i)
	{
		if (bad[i])
		{
			cout << "-\n";
			continue;
		}
		if (dist[i] == INF)
			cout << "*\n";
		else
			cout << dist[i] << '\n';
	}

	return 0;
}