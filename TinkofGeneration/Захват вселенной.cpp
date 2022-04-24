#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long m; cin >> m;
	long long n = (1ll << m);
	vector<long long> a(n), o(n);
	for (long long i = 0; i < n; ++i)
	{
		cin >> a[i];
		o[a[i]] = i;
	}

	if (n == 2)
	{
		cout << 2 << '\n';
		return 0;
	}

	long long t = 0;
	vector<long long> mnblock(n, -1), ob, obt(n);
	for (long long i = 0; i < n; ++i)
	{
		long long j = o[a[i] ^ (n - 1)];
		if (i < j)
		{
			ob.push_back(i);
			obt[i] = t;
			++t;
		}
		if (j < i)
		{
			--t;
			while (ob.size() && ob.back() > j) ob.pop_back();
			if (ob.size() && obt[ob.back()] == t)
			{
				mnblock[ob.back()] = i;
				ob.pop_back();
			}

		}
	}

	vector<vector<long long>> mblock(n, vector<long long>(2, -1));
	for (long long i = n - 1; i >= 0; --i)
	{
		long long j = mnblock[i], c = ((j - i + 1) / 2) % 2;

		if (j == -1) continue;

		mblock[i][c] = j;
		if (j + 1 < n)
			mblock[i][1 - c] = mblock[j + 1][1];
	}
	vector<long long> cnt(n);
	for (long long i = n - 1; i >= 0; --i)
	{
		if (mblock[i][0] == -1)
		{
			cnt[i] = 0;
			continue;
		}
		cnt[i] = 1;
		if (mblock[i][0] + 1 < n) cnt[i] += cnt[mblock[i][0] + 1];
	}

	cout << n * (n + 1) / 2 - accumulate(cnt.begin(), cnt.end(), 0ll) << '\n';

	return 0;
}