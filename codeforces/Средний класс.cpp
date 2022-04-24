#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long t; cin >> t;
	while (t--)
	{
		long long n, x; cin >> n >> x;
		vector<long long> a(n);
		for (auto& i : a) cin >> i;
		sort(a.begin(), a.end());
		long long sum = 0, insum = 0;
		long long b = lower_bound(a.begin(), a.end(), x) - a.begin();
		for (long long i = b; i < n; ++i)
			sum += a[i];
		insum += n - b;
		for (long long i = b - 1; i >= 0; --i)
			if (sum + a[i] >= x * (insum + 1))
			{
				sum += a[i];
				++insum;
			}
			else
				break;
		cout << insum << '\n';
	}

	return 0;
}