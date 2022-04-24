#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long n, m, k;

long long xmove = 0;
vector<long long> ymove;

void MoveY(long long a, long long b, long long val)
{
	ymove[a] = ((ymove[a] + val) % (n / m) + n / m) % (n / m);
	ymove[b + 1] = ((ymove[b + 1] - val) % (n / m) + n / m) % (n / m);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	vector<pair<long long, long long>> q(k);
	for (auto& i : q) cin >> i.first >> i.second;
	vector<long long> a(n);
	for (auto& i : a) cin >> i;
	ymove.resize(m + 1);
	for (long long i = k - 1; i >= 0; --i)
	{
		long long x = -q[i].second;
		if (q[i].first == 1)
		{
			x = (x % m + m) % m;
			xmove = (xmove + x) % m;
		}
		if (q[i].first == 2)
		{
			x = (x % n + n) % n;
			long long y = x % m;
			MoveY(0, m - 1, (x - y) / m);
			if (y != 0)
			{
				long long l = m - y, r = m - 1;
				l = ((l - xmove) % m + m) % m;
				r = ((r - xmove) % m + m) % m;
				if (l <= r)
					MoveY(l, r, 1);
				else
				{
					MoveY(l, m - 1, 1);
					MoveY(0, r, 1);
				}
				xmove = (xmove + y) % m;
			}
		}
	}
	partial_sum(ymove.begin(), ymove.end(), ymove.begin());
	for (long long i = 0; i < n / m; ++i)
		for (long long j = 0; j < m; ++j)
		{
			long long nj = ((j - xmove) % m + m) % m,
				ni = ((i - ymove[nj]) % (n / m) + n / m) % (n / m);
			cout << a[ni * m + nj] << ' ';
		}
	cout << '\n';

	return 0;
}