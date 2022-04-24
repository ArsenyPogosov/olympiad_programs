#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long n; cin >> n;
	vector<long long> a(n);
	for (auto& i : a) cin >> i;

	set<long long> s;
	for (long long i = 0, ts = 0; i < n; ++i)
		s.insert(ts += a[i]);
	long long res = n;
	for (long long i = n - 1, ts = 0; i >= 0; --i)
		res -= (s.find(ts += a[i]) != s.end());

	cout << res << '\n';

	return 0;
}