#include <iostream>
#include <vector>
//#include <queue>
#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

vector<int> tin, tout;
vector<list<int>> g;
int t = 0;

void DFS(int v)
{
	tin[v] = t++;
	for (auto&i : g[v])
		DFS(i);
	tout[v] = t++;
}

int main()
{
	int n;
	cin >> n;
	g.resize(n);
	int root;
	for (int i = 0; i < n; ++i)
	{
		int v;
		cin >> v;
		if (v != 0)
			g[v - 1].push_back(i);
		else
			root = i;
	}

	tin.resize(n);
	tout.resize(n);
	DFS(root);

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		if ((tin[a] < tin[b]) && (tout[b] < tout[a]))
			cout << "1\n";
		else
			cout << "0\n";
	}

	return 0;
}