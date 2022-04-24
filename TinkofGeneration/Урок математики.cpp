#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long x, res;

void checkdd(long long d, long long dd)
{
	bool good = true; long long h = d;
	while (h > 0)
	{
		if (h % dd != 1)
		{
			good = false;
			break;
		}
		h /= dd;
	}
	if (good && x / d < dd)
		res = min(res, dd);
}

void checkd(long long d)
{
	for (long long dd = 1; dd * dd <= d - 1; ++dd)
		if ((d - 1) % dd == 0)
		{
			checkdd(d, dd);
			checkdd(d, (d - 1) / dd);
		}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> x;
	res = x + 1;

	for (long long d = 1; d * d <= x; ++d)
		if (x % d == 0)
		{
			checkd(d);
			checkd(x / d);
		}

	cout << res << '\n';

	return 0;
}