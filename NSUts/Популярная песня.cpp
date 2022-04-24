#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long t = 39, p = (long long)(1e8) + 732543277;

long long ost(long long x)
{
	x %= p;
	if (x < 0) x += p;
	return x;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string s; cin >> s;
	long long n = s.size();

	vector<long long> tpow(22);
	tpow[0] = 1;
	for (long long i = 1; i < 22; ++i)
		tpow[i] = (tpow[i - 1] * t) % p;

	long long q; cin >> q;
	vector<vector<pair<long long, long long>>> query(21);
	for (long long j = 0; j < q; ++j)
	{
		string a; cin >> a;
		long long m = a.size();
		long long d;
		cin >> d;
		long long hsh = 0;
		for (long long i = 0; i < m; ++i)
			hsh = ost(hsh + (a[i] - '0') * tpow[m - i - 1]);
		query[m].emplace_back(hsh, d);
	}
	for (auto& i : query)
		if (i.size())
		{
			sort(i.begin(), i.end());
			vector<pair<long long, long long>> h;
			pair<long long, long long> tek = i[0];
			tek.second = 0;
			for (auto& j : i)
			{
				if (tek.first == j.first)
					tek.second += j.second;
				else
				{
					h.push_back(tek);
					tek = j;
				}
			}
			h.push_back(tek);
			i = h;
		}

	long long res = 0;
	for (long long l = 1; l < 21; ++l)
		if (query[l].size() && l <= n)
		{
			long long thsh = 0;
			for (long long i = 0; i < l; ++i)
				thsh = ost(thsh + (s[i] - '0') * tpow[l - i - 1]);
			thsh = ost(thsh);
			long long it = lower_bound(query[l].begin(), query[l].end(), pair<long long, long long>{ thsh, -1 }) - query[l].begin();
			if (it < query[l].size() && query[l][it].first == thsh)
				res += query[l][it].second;
			for (long long i = l; i < n; ++i)
			{
				thsh = ost((thsh - (s[i - l] - '0') * tpow[l - 1]) * 1ll * t + (s[i] - '0'));
				long long it = lower_bound(query[l].begin(), query[l].end(), pair<long long, long long>{ thsh, -(long long)(1e18) }) - query[l].begin();
				if (it < query[l].size() && query[l][it].first == thsh)
					res += query[l][it].second;
			}
		}

	cout << res << '\n';

	return 0;
}