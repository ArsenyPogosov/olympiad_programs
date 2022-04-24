#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<long long> a(n);
	for (auto& i : a) cin >> i;
	long long sum = accumulate(a.begin(), a.end(), 0ll);
	vector<long long> s(1 << (n - 1));
	{
		s[0] = a[0];
		int sb = 0;
		for (int i = 1; i < (1 << (n - 1)); ++i)
		{
			if (i >= (1 << (sb + 1))) ++sb;
			s[i] = s[i - (1 << sb)] + a[sb + 1];
		}
	}
	long long best =1e18;
	for (int i = 0; i < (1 << (n - 1)); ++i)
		best = min(best, abs(2 * s[i] - sum));
	cout << best << '\n';

	return 0;
}