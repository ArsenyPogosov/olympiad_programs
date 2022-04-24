#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n; cin >> n;
	vector<long long> a(n);
	for (auto& i : a) cin >> i;
	long long best = 0;
	for (long long i = 0; i < n; ++i)
		for (long long j = i; j < n; ++j)
			for (long long k = j; k < n; ++k)
				best = max(best, a[i] | a[j] | a[k]);
	cout << best << '\n';

	return 0;
}