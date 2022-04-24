#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n, t; cin >> n >> t;
	vector<long long> k(n);
	for (auto& i : k) cin >> i;
	long long l = -1, r = 1;
	while (true)
	{
		r *= 2;
		long long count = 0;
		for (auto& i : k) count += r / i;
		if (count >= t)
			break;
	}
	while (l + 1 < r)
	{
		long long m = (l + r) / 2;
		long long count = 0;
		for (auto& i : k) count += m / i;
		if (count < t)
			l = m;
		else
			r = m;
	}
	cout << r << '\n';

	return 0;
}