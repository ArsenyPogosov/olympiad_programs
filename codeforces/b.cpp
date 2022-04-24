//source: http://neerc.ifmo.ru/school/io/archive/20191005/problems-20191005.pdf
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

vector<int> color;
vector<list<int>> Graph;

vector<int> DFS(int v, int p = -1)
{
	vector<int> res = { 1, 1 };
	++res[1 - color[v]];
	for (auto&i: Graph[v])
		if (i != p)
		{
			auto h = DFS(i, v);
			res[0] += min(h[0] - 1, h[1]);
			res[1] += min(h[1] - 1, h[0]);
		}
	return res;
}

int main()
{
	int n;
	cin >> n;
	color.resize(n);
	Graph.resize(n);
	for (auto& i : color)
	{
		char h;
		cin >> h;
		i = h - '0';
	}
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		cin >> a >> b; --a; --b;
		Graph[a].push_back(b);
		Graph[b].push_back(a);
	}
	auto res = DFS(0);
	cout << min(res[0], res[1]);

	return 0;
}