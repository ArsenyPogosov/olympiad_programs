#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long movetosize(long long n, long long v)
{
	return (n - 2 * v - 1) * 2;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long t; cin >> t;
	while (t--)
	{
		long long n, l, r; cin >> n >> l >> r;
		long long from, count = 1;
		for (from = 0; from < n / 2; ++from)
		{
			if (from * 2 + 2 != n)
				count += (n - 2 * from - 1) * 2;
			else
				count += 1;
			if (count > l)
			{
				if (from * 2 + 2 != n)
					count -= (n - 2 * from - 1) * 2;
				else
					count -= 1;
				break;
			}
		}
		long long begins = -1;
		vector<long long> res; res.reserve(r - l + 1 + n * 2);
		if (from < n / 2)
		{
			begins = count;
			res.push_back(from);
			for (long long i = from; i < n / 2; ++i)
			{
				if (count >= r) break;
				long long end = n - i - 1;
				for (long long j = i + 1; j < end; ++j)
				{
					res.push_back(j);
					res.push_back(i);
				}
				res.push_back(end);
				if (i * 2 + 2 != n)
					res.push_back(from + 1);
				count += (n	- 2 * i - 1) * 2;
				if (i * 2 + 2 == n)
					--count;
			}
			if (n % 2 == 1)
			{
				++count;
				res.push_back(n / 2 + 1);
			}
		}
		if (count < r)
		{
			long long f = (n + 1) / 2;
			if (begins == -1)
			{
				for (f = (n + 1) / 2; f < n; ++f)
				{
					count += max(0ll, ((n + 1) / 2 - (n - f + 1)) * 2 + 2);
					if (count > r)
					{
						count -= max(0ll, ((n + 1) / 2 - (n - f + 1)) * 2 + 2);
						break;
					}
				}
				begins = count;
			}
			for (long long i = f; i < n; ++i)
			{
				if (count >= r) break;
				for (int j = n - i + 1; j < (n + 1) / 2 - 1; ++j)
				{
					res.push_back(j);
					res.push_back(i);
					count += 2;
				}
				res.push_back(n - i - 1);
				if (i + 1 < n)
					res.push_back(i + 1);
				else
					--count;
				count += 2;
			}
		}
		for (long long i = l - begins; i - l + begins <= r - l; ++i)
			cout << res[i] + 1 << ' ';
		cout << '\n';
	}

	return 0;
}