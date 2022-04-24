//source: file:///C:/Users/arsen/Downloads/13.11.19.%201%20%D0%B3%D1%80%D1%83%D0%BF%D0%BF%D0%B0.%20%D0%94%D0%B8%D0%BD%D0%B0%D0%BC%D0%B8%D0%BA%D0%B0%20%D0%BF%D0%BE%20%D0%BF%D0%BE%D0%B4%D0%BC%D0%BD%D0%BE%D0%B6%D0%B5%D1%81%D1%82%D0%B2%D0%B0%D0%BC%20%D0%B8%20%D0%BF%D1%80%D0%BE%D1%84%D0%B8%D0%BB%D1%8E.pdf
//status: coding

#include <bits/stdc++.h>
using namespace std;
//#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("network.in");
ofstream fout("network.out");
#define cin fin
#define cout fout
#endif
#pragma endregion

const  int INF = 1000000000;

int get(int mask, int i)
{
	return (mask >> i) & 1;
}

int xs, ys;
pair< int, int> points[24];

int sq(int n)
{
	return n * n;
}

int l(int i, int j)
{
	return sq(xs - points[i].first) + sq(ys - points[i].second) + sq(xs - points[j].first) + sq(ys - points[j].second) + sq(points[i].first - points[j].first) + sq(points[i].second - points[j].second);
}

int main()
{
	cin >> xs >> ys;
	int n; cin >> n;
	for (int i = 0; i < n; ++i) cin >> points[i].first >> points[i].second;
	vector< int> dp(1 << n, INF), dp1(1 << n, -1), dp2(1 << n, -1);
	dp[0] = 0;
	for (int mask = 0; mask < (1 << n) - 1; ++mask)
	{
		int h = mask ^ (mask + 1), v = -1;
		while (h > 0) { ++v; h /= 2; }
		for (int j = 0; j < n; ++j)
			if ((v != j) && (!get(mask, j)))
				if (dp[mask | (1 << v) | (1 << j)] > dp[mask] + l(v, j))
				{
					dp[mask | (1 << v) | (1 << j)] = dp[mask] + l(v, j);
					dp1[mask | (1 << v) | (1 << j)] = v;
					dp2[mask | (1 << v) | (1 << j)] = j;
				}
		if (dp[mask | (1 << v)] > dp[mask] + (sq(points[v].first - xs) + sq(points[v].second - ys)) * 2)
		{
			dp[mask | (1 << v)] = dp[mask] + (sq(points[v].first - xs) + sq(points[v].second - ys)) * 2;
			dp1[mask | (1 << v)] = v;
			dp2[mask | (1 << v)] = -1;
		}
	}
	cout << dp[(1 << n) - 1] << '\n';
	int tm = (1 << n) - 1;
	while (tm > 0)
	{
		cout << 0 << ' ' << dp1[tm] + 1 << ' ';
		int r = dp1[tm];
		if (dp2[tm] != -1)
		{
			cout << dp2[tm] + 1 << ' ';
			tm ^= (1 << (dp2[tm]));
		}
		tm ^= (1 << r);
	}
	cout << 0;

	return 0;
}