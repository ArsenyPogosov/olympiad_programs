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
	for (auto& i : Graph[v])
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

vector<long long> dp, va;

void DPDFS(int v, int p = -1)
{
	for (auto& i : Graph[v])
		if (i != p)
		{
			DPDFS(i, v);
			dp[v] += dp[i];
		}
	dp[v] += va[v];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	Graph.resize(n);
	vector<pair<int, int>> br; br.reserve(n - 1);
	for (long long i = 0; i < n - 1; ++i)
	{
		long long x, y; cin >> x >> y; --x; --y;
		Graph[x].push_back(y);
		Graph[y].push_back(x);
		br.push_back({ x, y });
	}
	buildVG(); buildST();
	int k; cin >> k;
	va.resize(n);
	for (int i = 0; i < k; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		int v = LCA(a, b);
		if (a == v) swap(a, b);
		if (b == v)
		{
			++va[a];
			--va[b];
		}
		else
		{
			++va[a];
			--va[v];
			++va[b];
			--va[v];
		}
	}
	dp.resize(n); DPDFS(0);
	for (auto& i : br)
	{
		if (LCA(i.first, i.second) == i.first) swap(i.first, i.second);
		cout << dp[i.first] << ' ';
	}

	return 0;
}