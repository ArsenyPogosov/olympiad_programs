//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/260495/problem/A
//status: coding

#include <bits/stdc++.h>
using namespace std;
#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("ufo.in");
ofstream fout("ufo.out");
#define cin fin
#define cout fout
#endif
#pragma endregion

long long n, m, u;
vector<list<long long>> Graph;
vector<long long> p, used;
long long T = 0;

struct UFO
{
	long long time, x, y;
	UFO() {};
};

void Read(UFO& o)
{
	string s; cin >> s;
	o.time = atoi(s.substr(0, 2).c_str()) * 60 + atoi(s.substr(3, 2).c_str());
	cin >> o.x >> o.y;
}

vector<UFO> Ord;

bool br(UFO a, UFO b)
{
	return (a.time <= b.time) && ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)) * 3600 <= (b.time - a.time) * (b.time - a.time) * u * u;
}

bool DFS(long long v)
{
	if (used[v] == T) return false;
	used[v] = T;
	for (auto& i : Graph[v])
		if (p[i] == -1 || DFS(p[i]))
		{
			p[i] = v;
			return true;
		}
	return false;
}

int main()
{
	cin >> n >> u; m = n;
	Ord.resize(n);
	for (auto& i : Ord) Read(i);
	Graph.resize(n);
	for (long long i = 0; i < n; ++i)
		for (long long j = 0; j < n; ++j)
			if (i != j && br(Ord[i], Ord[j]))
				Graph[i].push_back(j);

	p.resize(m, -1); used.resize(n, -1);
	for (long long i = 0; i < n; ++i)
		if (DFS(i))
			++T;

	long long count = 0;
	for (long long i = 0; i < m; ++i)
		if (p[i] >= 0)
			++count;
	cout << n - count << '\n';

	return 0;
}