#include <iostream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

const int INF = 100000;

int n;
vector<vector<int>> dp;
vector<int> dsize;
vector<int> l, r;

int Dsize(int v)
{
	if (dsize[v] != -1)
		return dsize[v];
	dsize[v] = 1;
	if (l[v] >= 0)
		dsize[v] += Dsize(l[v]);
	if (r[v] >= 0)
		dsize[v] += Dsize(r[v]);
	return dsize[v];
}

int res(int v, int s)
{
	if (dp[v][s] != -1)
		return dp[v][s];

	if (s == 0)
		return dp[v][s] = Dsize(v);
	if (l[v] == -1 && r[v] == -1)
	{
		if (s == 1)
			return dp[v][s] = 0;
		return dp[v][s] = INF;
	}
	if (l[v] == -1 || r[v] == -1)
	{
		int u = max(l[v], r[v]);
		if (s == 1)
			return dp[v][s] = Dsize(u);
		if (s == 2)
			return dp[v][s] = Dsize(u) - 1;
		return dp[v][s] = INF;
	}

	int a = s - 1, b = max(s - 2, 0);
	
	return dp[v][s] = min(min(res(l[v], a) + res(r[v], a), res(l[v], a) + res(r[v], b)), res(l[v], b) + res(r[v], a));
}

int main()
{
	cin >> n;
	l.resize(n);
	r.resize(n);
	dp.resize(n, vector<int>(n + 1, -1));
	dsize.resize(n, -1);
	for (int i = 0; i < n; ++i)
	{
		cin >> l[i] >> r[i];
		--l[i];
		--r[i];
	}

	int ans = INF;
	for (int i = 0; i <= n; ++i)
		ans = min(ans, res(0, i));
	cout << ans;

	return 0;
}