#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

double intersect(long long a, long long b, long long c, long long d)
{
	return double(d - b) / double(a - c);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long n; cin >> n;
	vector<long long> a(n), b(n);
	for (long long i = 0; i < n; ++i)
		cin >> a[i] >> b[i];
	long long q; cin >> q;
	long long good = true;
	while (q--)
	{
		long long c, d; cin >> c >> d;
		if (!good) c ^= ((1 << 29) - 1), d ^= ((1 << 29) - 1);

		double bx = -1;
		for (long long i = 0; i < n; ++i)
			bx = max(bx, intersect(a[i], b[i], c, d));

		if (bx < 0)
		{
			cout << "No cross\n";
			good = false;
		}
		else
		{
			cout << fixed << setprecision(16) << bx << '\n';
			good = true;
		}
	}

	return 0;
}