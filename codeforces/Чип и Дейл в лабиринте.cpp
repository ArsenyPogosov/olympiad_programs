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
vector<list<pair<long long, bool>>> Graph;
vector<long long> vg(1), d, pos;
vector<vector<long long>> st;

void VGDFS(long long v, long long p = -1)
{
	if (p >= 0) d[v] = d[p] + 1;
	vg.push_back(v);
	pos[v] = vg.size() - 1;
	for (auto& i : Graph[v])
		if (i.first != p)
		{
			VGDFS(i.first, v);
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

vector<long long> dp1, dp2;

void DPDFS(int v, int p = -1, bool rev = true)
{
	if (p >= 0)
	{
		if (rev)
		{
			dp1[v] = dp1[p];
			dp2[v] = v;
		}
		else
		{
			dp1[v] = v;
			dp2[v] = dp2[p];
		}
	}
	for (auto& i : Graph[v])
		if (i.first != p)
			DPDFS(i.first, v, !i.second);
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
		Graph[x].push_back({ y, true });
		Graph[y].push_back({ x, false });
		br.push_back({ x, y });
	}
	buildVG(); buildST(); dp1.resize(n); dp2.resize(n); DPDFS(0);
	int m; cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b; --a; --b; int v = LCA(a, b);
		if ((LCA(dp1[a], v) == dp1[a]) && (LCA(dp2[b], v) == dp2[b]))
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}