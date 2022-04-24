#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n; cin >> n;
	vector<long long> a(n);
	cin >> a[0]; a[0] = (a[0] % n + n) % n;
	for (long long i = 1; i < n; ++i)
	{
		long long h; cin >> h;
		a[i] = ((a[i - 1] + h) % n + n) % n;
	}
	vector<int> c(n);
	long long res = 0;
	for (long long i = n - 1; i >= 0; --i)
	{
		res += c[a[i]];
		++c[a[i]];
	}
	res += c[0];
	cout << res << '\n';

	return 0;
}