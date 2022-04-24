//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/260745/problem/A
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

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, t; cin >> n >> t;
	vector<int> d(n), s(n), u(n);
	for (int i = 0; i < n; ++i) cin >> d[i] >> s[i] >> u[i];
	int ms = 1, mt = 0;
	vector<vector<int>> season(1e5 + 1);
	for (int i = 0; i < n; ++i)
	{
		if (d[i] + mt <= t)
		{
			mt += d[i];
			if (ms <= 1e5)
				season[ms].push_back(i + 1);
		}
		else
		{
			if ((t - mt) - s[i] < u[i])
			{
				mt = 0;
				++ms;
			}
			else
			{
				d[i] -= (t - mt) - s[i];
				mt = u[i];
				if (ms <= 1e5)
					season[ms].push_back(i + 1);
				++ms;
			}
			if ((mt + d[i] > t) && (s[i] + u[i] >= t))
			{
				cout << -1;
				return 0;
			}
			while (d[i])
			{
				if (mt + d[i] <= t)
				{
					mt += d[i];
					d[i] = 0;
					if (ms <= 1e5)
						season[ms].push_back(i + 1);
				}
				else
				{
					d[i] -= (t - mt) - s[i];
					mt = u[i];
					if (ms <= 1e5)
						season[ms].push_back(i + 1);
					++ms;
				}
			}
		}
	}
	cout << ms << '\n';
	if (ms <= 1e5)
		for (int i = 1; i <= ms; ++i)
		{
			for (auto& j : season[i]) cout << j << ' ';
			cout << '\n';
		}

	return 0;
}