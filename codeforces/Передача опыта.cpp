//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/260745/problem/D
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

const long long P = 1e9 + 7;

int n, k;
vector<pair<int, int>> Graph[1500000];
int mc[1500000], sz[1500000];
int C[1500001];
int dp[1500000], dpk[1500000];

long long Count = 0;

void inline DFS(int v, int p = -1, int c = -1)
{
	dp[v] = 0;
	int bef;
	if (c != -1)
	{
		bef = mc[c];
		mc[c] = v;
	}
	sz[v] = 1;
	for (auto& i : Graph[v])
		if (i.first != p)
		{
			DFS(i.first, v, i.second);
			sz[v] += sz[i.first];
		}
	if (c != -1)
	{
		if (bef >= 0)
			dp[bef] -= sz[v];
		else
			dpk[c] -= sz[v];
		mc[c] = bef;
	}
	if (p >= 0)
	{
		dp[v] += sz[v];
		Count = ((((long long)(dp[v]) * (n - dp[v])) % P) * (long long)(C[c + 1]) + Count) % P;
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < k; ++i) mc[i] = -1;
	for (int i = 1; i <= n - 1; ++i)
	{
		int b, t; cin >> b >> t; --b; --t;
		Graph[i].push_back({ b, t });
		Graph[b].push_back({ i, t });
	}
	int a, b, c; cin >> a >> b >> c;
	cin >> C[0];
	for (int i = 1; i <= k; ++i) C[i] = ((long long)(a) * (C[i - 1]) + b) % c;
	DFS(min(100, n - 1));
	for (int i = 0; i < k; ++i)
		Count = ((((long long)(n + dpk[i]) * (-dpk[i])) % P) * (long long)(C[i + 1]) + Count) % P;
	cout << Count;
	
	return 0;
}