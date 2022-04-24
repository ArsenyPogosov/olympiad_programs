#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n, m; cin >> n >> m;
	vector<long long> a(m), b(m), c(m);
	for (long long i = 0; i < m; ++i)
		cin >> a[i] >> b[i];
	for (long long i = 0; i < n; ++i)
	{
		string name; cin >> name;
		long long t, cnt; cin >> t >> cnt; --t;
		if (name == "pen") c[t] += cnt;
		else c[t] -= cnt;
	}
	long long res = 0;
	for (long long i = 0; i < m; ++i)
		res += abs(c[i]) * min(a[i], b[i]);
	cout << res << '\n';

	return 0;
}