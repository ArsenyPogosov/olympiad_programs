//source: 
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

const long long INF = 1000000000;
long long n;
vector<list<pair<long long, long long>>> Graph;
vector<vector<long long>> Rd;

list<long long> DFS(long long v, long long p = -1)
{
	Rd[v][v] = 0;
	if (Graph[v].size() == 0) return { v };
	if (Graph[v].size() == 1 && p != -1) return { v };
	vector<list<long long>> res; res.reserve(Graph[v].size() + 1);
	for (auto& i : Graph[v])
		if (i.first != p)
		{
			auto x = DFS(i.first, v);
			for (auto&j: x)
				Rd[v][j] = Rd[j][v] = Rd[i.first][j] + i.second;
			res.push_back(x);
		}
	for (long long i = 0; i < res.size(); ++i)
		for (long long j = i + 1; j < res.size(); ++j)
			for (auto&k: res[i]) for (auto& l : res[j])
				Rd[k][l] = Rd[l][k] = Rd[k][v] + Rd[v][l];
	for (long long i = 1; i < res.size(); ++i)
		res[0].merge(res[i]);
	res[0].push_back(v);
	return res[0];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> n;
	vector<vector<long long>> Gd(n, vector<long long>(n));
	for (auto& i : Gd)  for (auto& j : i) cin >> j;

	vector<long long> order(n - 1); 
	iota(order.begin(), order.end(), 1);
	sort(order.begin(), order.end(), [&](long long a, long long b) { 
		return Gd[0][a] < Gd[0][b]; 
	});
	Graph.resize(n);
	list<long long> c; c.push_front(0);
	for (long long i = 0; i < n - 1; ++i)
	{
		bool add = false;
		for (auto& j : c)
			if (Gd[0][order[i]] == Gd[0][j] + Gd[j][order[i]])
			{
				Graph[j].push_back({ order[i], Gd[j][order[i]] });
				Graph[order[i]].push_back({ j, Gd[j][order[i]] });
				c.push_front(order[i]);
				add = true;
				break;
			}
		if (!add)
		{
			cout << "NO\n";
			return 0;
		}
	}

	Rd.resize(n, vector<long long>(n));
	DFS(0);

	bool flag = true;
	for (long long i = 0; i < n && flag; ++i)
		for (long long j = 0; j < n && flag; ++j)
			if (Gd[i][j] != Rd[i][j])
			{
				flag = false;
				break;
			}
	for (long long i = 0; i < n && flag; ++i)
		for (auto& j : Graph[i])
			if (j.second == 0)
			{
				flag = false;
				break;
			}

	cout << (flag ? "YES\n" : "NO\n");

	return 0;
}