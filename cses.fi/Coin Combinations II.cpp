#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int p = 1e9 + 7;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, x; cin >> n >> x;
	vector<int> c(n);
	for (auto& i : c) cin >> i;
	vector<int> d(x + 1, 0); d[0] = 1;
	for (auto& i : c)
		for (int j = 1; j <= x; ++j)
			if (j >= i)
				d[j] = (d[j] + d[j - i]) % p;
	cout << d[x] << '\n';

	return 0;
}