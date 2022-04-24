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

vector<list<long long>> Graph;
vector<long long> d, dr, P;
vector<map<long long, long long>> db;

long long DFS(long long v, long long p = -1)
{
	d[v] = 0;
	P[v] = p;
	pair<long long, long long> m1, m2, n;
	m1 = m2 = { -1, -1 };
	for (auto&i: Graph[v])
		if (i != p)
		{
			n = { DFS(i, v) + 1, i };
			if (m2 < n) swap(m2, n);
			if (m1 < m2) swap(m1, m2);
		}
	for (auto& i : Graph[v])
		if (i != p)
		{
			if (i != m1.second)
				db[v].insert({ i, m1.first });
			else
				db[v].insert({ i, m2.first });
		}
	d[v] = max(m1.first, 0LL);
	return d[v];
}

void DFS2(long long v, long long p = -1)
{
	if (p == -1)
		dr[v] = 0;
	else
		dr[v] = max(dr[p], db[p][v]) + 1; 
	for (auto& i : Graph[v])
		if (i != p)
			DFS2(i, v);
}

long long cool(long long v)
{
	long long res = 0;
	for (auto& i : Graph[v])
		if (i != P[v])
			res += (d[i] + 1) * (d[i] + 1);
	return res + dr[v]*dr[v];
}

int main()
{
	long long n;
	cin >> n;
	Graph.resize(n);
	d.resize(n, -1);
	dr.resize(n, -1);
	db.resize(n);
	P.resize(n);
	for (long long i = 0; i < n - 1; ++i)
	{
		long long h1, h2;
		cin >> h1 >> h2; --h1; --h2;
		Graph[h1].push_back(h2);
		Graph[h2].push_back(h1);
	}
	dr[0] = 0;
	DFS(0);
	DFS2(0);
	long long mc = cool(0), mv = 0;
	for (long long i = 1; i < n; ++i)
	{
		long long nc = cool(i);
		if (nc < mc)
		{
			mc = nc;
			mv = i;
		}
	}
	cout << mc << ' ' << mv + 1;

	return 0;
}