#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long q; cin >> q;

	while (q--)
	{
		long long k;
		cin >> k; --k;

		long long len = 1, tp = 1;
		while (k >= tp * 9 * len)
		{
			k -= tp * 9 * len;
			tp *= 10;
			++len;
		}

		long long targ = tp + k / len;
		cout << to_string(targ)[k % len] << '\n';
	}

	return 0;
}