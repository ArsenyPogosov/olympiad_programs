//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/260272/problem/E
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
vector<list<long long>> Graph;
vector<long long> vg(1), d, pos;
vector<vector<long long>> st;

void VGDFS(long long v, long long p = -1)
{
	if (p >= 0) d[v] = d[p] + 1;
	vg.push_back(v);
	pos[v] = vg.size() - 1;
	for (auto&i: Graph[v])
		if (i != p)
		{
			VGDFS(i, v);
			vg.push_back(v);
		}
}

void buildVG()
{
	vg.reserve(n * 2);
	d.resize(n);
	pos.resize(n);
	VGDFS(0);
}

long long clog2(long long k)
{
	long long i = 0;
	while ((1 << (i + 1)) <= k) ++i;
	return i;
}

long long dmin(long long a, long long b)
{
	return (d[a] <= d[b] ? a : b);
}

void buildST()
{
	long long N = vg.size(), M = clog2(N + 1) + 2;
	st.resize(M, vector<long long>(N));
	for (long long i = 0; i < N; ++i) st[0][i] = vg[i];
	for (long long i = 1; i < M; ++i)
		for (long long j = 0; j < N; ++j)
			st[i][j] = dmin(st[i - 1][j], st[i - 1][min(N - 1, j + (1 << (i - 1)))]);
}

long long stmin(long long l, long long r)
{
	if (l > r) swap(l, r);
	long long i = clog2(r - l + 1);
	return dmin(st[i][l], st[i][r - (1 << i) + 1]);
}

long long LCA(long long v, long long u)
{
	return stmin(pos[v], pos[u]);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long m; cin >> n >> m;
	Graph.resize(n);
	for (long long i = 1; i < n; ++i)
	{
		long long x; cin >> x;
		Graph[x].push_back(i);
		Graph[i].push_back(x);
	}
	buildVG(); buildST();
	long long a1, a2, b1, b2; cin >> a1 >> a2; b1 = a1; b2 = a2;
	long long x, y, z; cin >> x >> y >> z; x %= n; y %= n; z %= n;
	long long sum = 0;
	for (long long i = 0; i < m; ++i)
	{
		long long v = LCA(b1, b2); sum += v;
		a1 = (x * a1 + y * a2 + z) % n;
		a2 = (x * a2 + y * a1 + z) % n;
		b1 = (a1 + v) % n;
		b2 = a2;
	}
	cout << sum;

	return 0;
}