//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/258385/problems
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
	long long n, m;
	cin >> n >> m;
	deque<long long> a;
	for (long long i = 0; i < n; ++i) { long long h; cin >> h; a.push_back(h); };
	vector<pair<long long, long long>> ans(n - 1);
	for (auto& i : ans)
	{
		long long x, y;
		x = a.front(); a.pop_front();
		y = a.front(); a.pop_front();
		i = { x, y };
		if (x < y) swap(x, y);
		a.push_front(x);
		a.push_back(y);
	}
	vector<long long> res(n);
	for (auto& i : res) { i = a.front(); a.pop_front(); }
	for (long long i = 0; i < m; ++i)
	{
		long long h;
		cin >> h;
		if (h < n)
			cout << ans[h - 1].first << ' ' << ans[h - 1].second << '\n';
		else
		{
			cout << res[0] << ' ' << res[(h - 1) % (n - 1) + 1] << '\n';
		}
	}

	return 0;
}