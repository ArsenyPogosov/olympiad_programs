#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long k;
bool check(string s)
{
	if (k <= 1) return true;

	for (long long i = 1, l = 1; i < s.size(); ++i)
	{
		if (s[i - 1] != s[i])
			l = 0;
		++l;

		if (l >= k) 
			return true;
	}

	return false;
}

long long ans(string a)
{
	long long n = a.size();
	long long res = 0;
	for (long long mask = 0; mask < (1ll << (n - 1)); ++mask)
	{
		vector<pair<long long, long long>> seg;
		for (long long l = 0, r = 0; r < n; ++r)
		{
			if (r == n - 1 || ((mask >> r) & 1ll))
			{
				seg.emplace_back(l, r);
				l = r + 1;
			}
		}
		bool bad0 = (seg[0].second - seg[0].first + 1 < k), bad1 = true;
		for (long long i = 1; i < seg.size(); ++i)
			if (seg[i].second - seg[i].first + 1 >= k)
				bad1 = false;
		if (bad0 && bad1) continue;

		long long sres0 = 1, sres1 = 0;
		vector<long long> res0(10), res1(10);
		for (long long i = 0; i < seg.size(); ++i)
		{
			long long l = seg[i].first, r = seg[i].second;
			long long nsres0 = 0, nsres1 = 0;
			vector<long long> nres0(10), nres1(10);
			for (long long j = (i == 0 && bad1); j < 10; ++j)
			{
				nsres1 += (sres1 - res1[j]);
				nres1[j] += (sres1 - res1[j]);
				long long reg = 0;
				for (long long ii = l; ii <= r; ++ii)
				{
					if (a[ii] - '0' < j)
					{
						reg = 1;
						break;
					}
					if (a[ii] - '0' > j)
					{
						reg = -1;
						break;
					}
				}
				if (reg == -1)
				{
					nsres1 += (sres0 - res0[j]);
					nres1[j] += (sres0 - res0[j]);
				}
				if (reg == 0)
				{
					nsres0 += (sres0 - res0[j]);
					nres0[j] += (sres0 - res0[j]);
				}
			}

			sres0 = nsres0; sres1 = nsres1;
			res0 = nres0; res1 = nres1;
		}

		res += sres0 + sres1;
	}

	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string a, b; cin >> a >> b >> k;

	cout << ans(b) - ans(a) + check(a) << '\n';

	return 0;
}