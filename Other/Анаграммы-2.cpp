#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

const long long p1 = 1e9 + 9;
const long long p2 = 1e7 + 7;
const long long t1 = 37;
const long long t2 = 53;

long long qpow1(long long a, long long k)
{
	if (k == 0) return 1;

	long long res = qpow1(a, k / 2);
	return (res * res % p1 * (k % 2 ? a : 1)) % p1;
}

long long qpow2(long long a, long long k)
{
	if (k == 0) return 1;

	long long res = qpow2(a, k / 2);
	return (res * res % p2 * (k % 2 ? a : 1)) % p2;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	srand(time(0) + 228 + rand());

	int n; cin >> n;
	vector<int> a(n);
	for (auto& i : a)
		cin >> i, i += 1337;
	int m; cin >> m;
	vector<int> b(m);
	for (auto& i : b)
		cin >> i, i += 1337;

	int res = 0;
	for (int k = min(n, m); k >= 1 && res <= 0; --k)
	{
		long long h1 = 0, h2 = 0;
		set<pair<int, int>> s;
		for (int i = 0; i < k; ++i)
		{
			h1 = (h1 + qpow1(t1, hash<int>()(a[i]))) % p1;
			h2 = (h2 + qpow2(t2, hash<int>()(a[i]))) % p2;
		}
		s.insert({ h1, h2 });
		for (int i = k; i < n; ++i)
		{
			h1 = ((h1 - qpow1(t1, hash<int>()(a[i - k]))) % p1 + p1) % p1;
			h1 = (h1 + qpow1(t1, hash<int>()(a[i]))) % p1;
			h2 = ((h2 - qpow2(t2, hash<int>()(a[i - k]))) % p2 + p2) % p2;
			h2 = (h2 + qpow2(t2, hash<int>()(a[i]))) % p2;
			s.insert({ h1, h2 });
		}
		h1 = h2 = 0;
		for (int i = 0; i < k; ++i)
		{
			h1 = (h1 + qpow1(t1, hash<int>()(b[i]))) % p1;
			h2 = (h2 + qpow2(t2, hash<int>()(b[i]))) % p2;
		}
		if (s.count({ h1, h2 }))
		{
			res = k;
			break;
		}
		for (int i = k; i < m; ++i)
		{
			h1 = ((h1 - qpow1(t1, hash<int>()(b[i - k]))) % p1 + p1) % p1;
			h1 = (h1 + qpow1(t1, hash<int>()(b[i]))) % p1;
			h2 = ((h2 - qpow2(t2, hash<int>()(b[i - k]))) % p2 + p2) % p2;
			h2 = (h2 + qpow2(t2, hash<int>()(b[i]))) % p2;
			if (s.count({ h1, h2 }))
			{
				res = k;
				break;
			}
		}
	}

	cout << res << '\n';

	return 0;
}