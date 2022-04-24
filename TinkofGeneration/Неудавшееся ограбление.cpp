#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

bool in(long long a, long long b, long long x)
{
	if (a <= b)
		return (a <= x) && (x <= b);
	else
		return (a <= x) || (x <= b);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long n, l; cin >> n >> l;
	long long cnt = 0;
	for (long long i = 0; i < n; ++i)
	{
		long long r, s, t; cin >> r >> s >> t; --r; --s;
		if (t >= l * 2 - 3)
		{
			++cnt;
			continue;
		}

		long long a = s % (l * 2 - 2), b = (s + t) % (l * 2 - 2);
		if (in(a, b, r) || (r > 0 && in(a, b, l * 2 - r - 2)))
			++cnt;
	}

	cout << cnt << '\n';

	return 0;
}