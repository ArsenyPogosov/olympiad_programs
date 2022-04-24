#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, x; cin >> n >> x;
	vector<int> c(n);
	for (auto& i : c) cin >> i;
	vector<int> d(x + 1, 1e9); d[0] = 0;
	for (int i = 1; i <= x; ++i)
		for (auto& j : c)
			if (i >= j)
				d[i] = min(d[i], d[i - j] + 1);
	cout << (d[x] < 1e9 ? d[x] : -1) << '\n';

	return 0;
}