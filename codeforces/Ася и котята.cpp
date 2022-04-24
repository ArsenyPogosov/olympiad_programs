//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/260252/problem/C
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

long long n;
vector<long long> mass, dsu, r;
vector<list<int>> order;

long long get(long long x)
{
	return (dsu[x] == -1 ? x : dsu[x] = get(dsu[x]));
}

void unite(long long x, long long y)
{
	x = get(x); y = get(y);
	if (x == y) return;

	if (r[x] > r[y]) swap(x, y);
	dsu[x] = y;
	if (r[x] == r[y]) ++r[y];
	order[y].splice(order[y].begin(), order[x]);
}

void buildDSU()
{
	dsu.resize(n, -1);
	r.resize(n);
	order.resize(n);
	for (int i = 0; i < n; ++i) order[i] = { i };
}

int main()
{
	cin >> n;
	buildDSU();
	for (long long i = 0; i < n - 1; ++i)
	{
		int x, y; cin >> x >> y;
		unite(x - 1, y - 1);
	}
	for (auto& i : order[get(0)]) cout << i + 1 << ' ';

	return 0;
}