#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n; cin >> n;
	vector<long long> x(n);
	for (auto& i : x) cin >> i;
	vector<long long> ps(n);
	partial_sum(x.begin(), x.end(), ps.begin());
	long long res = x[0], mx = ps[n - 1];
	for (long long i = n - 2; i >= 0; --i)
	{
		res = max(res, mx - ps[i]);
		mx = max(mx, ps[i]);
	}
	res = max(res, mx);
	cout << res << '\n';

	return 0;
}