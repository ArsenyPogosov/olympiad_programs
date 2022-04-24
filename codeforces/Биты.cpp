#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long bit(long long x, long long i)
{
	return (x & (1ll << i));
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		long long l, r; cin >> l >> r;
		int pos = 63;
		long long count = 0;
		while (pos >= 0 && bit(l, pos) == bit(r, pos)) { count += bit(l, pos); --pos; }
		if (pos >= 0)
		{
			if (r % (1ll << (pos + 1)) == (1ll << (pos + 1)) - 1)
				count += (1ll << (pos + 1)) - 1;
			else
				count += (1ll << (pos)) - 1;
		}
		cout << count << '\n';
	}

	return 0;
}