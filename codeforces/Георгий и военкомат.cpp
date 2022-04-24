//source: https://codeforces.com/gym/102330/problem/E
//status: solved

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
	long long n, k;
	cin >> n >> k;
	vector<long long> t(k);
	for (auto& i : t)
		cin >> i;

	vector<vector<long long>> guy(n, vector<long long>(3));
	for (long long i = 0; i < n; ++i)
	{
		guy[i][0] = i;
		cin >> guy[i][1] >> guy[i][2];
		if (guy[i][2] == 0)
			guy[i][2] = 1000000000000000;
	}
	sort(guy.begin(), guy.end(), [](vector<long long>& a, vector<long long>& b) {
		return a[1] < b[1] || (a[1] == b[1] && a[0] < b[0]);
	});

	vector<long long> ans(n), toutmax(k + 1, -1);
	vector<vector<long long>> tout(n, vector<long long>(k + 1, -1));
	tout[0][0] = guy[0][1];
	toutmax[0] = max(toutmax[0], tout[0][0]);
	for (long long i = 0; i < k; ++i)
	{
		tout[0][i + 1] = tout[0][i] + t[i];
		if (tout[0][i + 1] > guy[0][1] + guy[0][2])
		{
			tout[0][i + 1] = guy[0][1] + guy[0][2];
			toutmax[i + 1] = max(toutmax[i + 1], tout[0][i + 1]);
			ans[guy[0][0]] = -1;
			break;
		}
		toutmax[i + 1] = max(toutmax[i + 1], tout[0][i + 1]);
	}
	if (ans[guy[0][0]] != -1) ans[guy[0][0]] = tout[0][k] - guy[0][1];
	for (long long j = 1; j < n; ++j)
	{
		tout[j][0] = guy[j][1];
		toutmax[0] = max(toutmax[0], tout[j][0]);
		for (long long i = 0; i < k; ++i)
		{
			tout[j][i + 1] = max(tout[j][i], toutmax[i + 1]) + t[i];
			if (tout[j][i + 1] > guy[j][1] + guy[j][2])
			{
				if (guy[j][1] + guy[j][2] >= max(tout[j][i], toutmax[i + 1]))
					tout[j][i + 1] = guy[j][1] + guy[j][2];
				else
					tout[j][i + 1] = -1;
				ans[guy[j][0]] = -1;
				toutmax[i + 1] = max(toutmax[i + 1], tout[j][i + 1]);
				break;
			}
			toutmax[i + 1] = max(toutmax[i + 1], tout[j][i + 1]);
		}
		if (ans[guy[j][0]] != -1) ans[guy[j][0]] = tout[j][k] - guy[j][1];
	}
	for (auto& i : ans) cout << i << ' ';

		return 0;
}