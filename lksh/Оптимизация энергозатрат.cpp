#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long INF = 1e18;

vector<long long> pow3 = { 1, 3, 9, 27, 81 };

long long get(long long mask, long long i)
{
	mask %= pow3[i + 1];
	return mask - (mask % pow3[i]);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n, m; cin >> n >> m;
	vector<long long> s(n);
	vector<pair<long long, long long>> otr(m);
	for (auto& i : s) cin >> i;
	for (auto& i : otr) 
	{
		cin >> i.first >> i.second; 
		--i.first; --i.second;
	}
	vector<long long> mres(pow3[m], 0);
	for (long long i = 0; i < n; ++i)
	{
		for (long long mask = 0; mask < pow3[m]; ++mask)
		{
			if (mres[mask] != INF)
			{
				bool ok = true;
				long long day = m;
				for (long long j = 0; j < m; ++j)
					if (get(mask, j) == pow3[j])
					{
						if (i < otr[j].first || otr[j].second < i)
						{
							ok = false;
							break;
						}
						if (day == m) day = j;
					}
				if (!ok)
					mres[mask] = INF;
				else
					mres[mask] += s[i] * day;
			}
			for (long long j = 0; j < m; ++j)
				if (get(mask, j) > 0)
					mres[mask] = min(mres[mask], mres[mask - pow3[j]]);
		}
	}
	cout << mres[pow3[m] - 1] << '\n';

	return 0;
}