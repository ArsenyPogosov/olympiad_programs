//source: https://codeforces.com/gym/102348/problem/B
//status: solved

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

vector<int> goodway;
vector<bool> colored;
vector<list<pair<int, int>>> Graph;

bool DFS(int v, int parent = -1)
{
	bool flag = colored[v];
	for (auto&i : Graph[v])
		if (i.first != parent)
			flag |= goodway[i.second] = DFS(i.first, v);
	return flag;
}

int main()
{
	int n, k;
	cin >> n >> k;
	colored.resize(n);
	int start;
	cin >> start; --start;
	colored[start] = true;
	for (int i = 1; i < k; ++i)
	{
		int h;
		cin >> h;
		colored[h - 1] = true;
	}

	Graph.resize(n);
	goodway.resize(2 * n - 2, true);
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		cin >> a >> b; --a; --b;
		Graph[a].emplace_back(b, i * 2);
		Graph[b].emplace_back(a, i * 2 + 1);
	}

	DFS(start);
	list<int> ans;
	for (int i = 0; i < n; ++i)
	{
		bool flag = !colored[i];
		for (auto& j : Graph[i])
			if (!(flag &= goodway[j.second])) break;
		if (flag) ans.push_back(i + 1);
	}
	cout << ans.size() << '\n';
	for (auto& i : ans) cout << i << ' ';

	return 0;
}