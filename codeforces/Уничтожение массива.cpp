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
vector<long long> mass, dsu, r, sum;
set<long long> sums;

long long get(long long x)
{
	if (dsu[x] == -2) return -2;
	return (dsu[x] == -1 ? x : dsu[x] = get(dsu[x]));
}

void unite(long long x, long long y)
{
	x = get(x); y = get(y);
	if (x == -2 || y == -2) return;
	if (x == y) return;

	sums.erase(sum[x]);
	sums.erase(sum[y]);
	if (r[x] > r[y]) swap(x, y);
	dsu[x] = y;
	if (r[x] == r[y]) ++r[y];
	sum[y] += sum[x];
	sums.insert(sum[y]);
}

void add(long long i)
{
	dsu[i] = -1;
	sums.insert(sum[i]);
	unite(max(i - 1, 0LL), i);
	unite(i, min(i + 1, n - 1));
}

void buildDSU()
{
	dsu.resize(n, -2);
	r.resize(n);
	sum = mass;
}

int main()
{
	cin >> n;
	mass.resize(n);
	for (auto& i : mass) cin >> i;
	vector<long long> del(n);
	for (auto& i : del) cin >> i;
	vector<long long> res(n); res[n - 1] = 0;
	buildDSU();
	for (long long i = n - 2; i >= 0; --i)
	{
		add(del[i + 1] - 1);
		res[i] = *--sums.end();
	}
	for (auto& i : res) cout << i << '\n';


	return 0;
}
