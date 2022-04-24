//source: http://neerc.ifmo.ru/school/io/archive/20191019/problems-20191019-advanced.pdf
//status: coding

#include <bits/stdc++.h>
using namespace std;
//#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif
#pragma endregion

vector<list<int>> Graph;
vector<int> fire;

int DFS(int v, int p = -1)
{
	fire[v] = 1;
	int res = Graph[v].size();
	for (auto& i : Graph[v])
		if (fire[i] == 0 && i != p)
			res += DFS(i, v);
	return res;
}

int main()
{
	int n, m;
	cin >> n >> m;
	Graph.resize(n);
	fire.resize(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b; --a; --b;
		Graph[a].push_back(b);
		Graph[b].push_back(a);
	}
	for (int i = 0; i < n; ++i)
		if (fire[i] == 0)
			if ((DFS(i) / 2) % 2 == 1)
			{
				cout << "YES";
				return 0;
			}
	cout << "NO";

	return 0;
}