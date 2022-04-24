#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2", "popcnt")

#include <bits/stdc++.h>
#include <bitset>
using namespace std;

istringstream gen(int n)
{
	ostringstream res;
	res << n << '\n';
	for (int i = 0; i < n; ++i, res << '\n')
		for (int j = 0; j < n; ++j)
			res << char(rand() % 2 + '0');

	return istringstream(res.str());
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	//istringstream cin = gen(3000);
	//double t = clock();

	int n; cin >> n;
	vector<bitset<3000>> a(n);
	for (auto& i : a) cin >> i;

	long long res = 0;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
		{
			int cnt = (a[i] & a[j]).count();
			res += cnt * (cnt - 1);
		}
	res >>= 1;

	cout << res << '\n';

	//cout << (clock() - t) / CLOCKS_PER_SEC << '\n';

	return 0;
}