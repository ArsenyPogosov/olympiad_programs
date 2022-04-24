#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	int m = 0; for (int nn = n - 1; nn > 0; ++m, nn /= 2);

	vector<vector<int>> res(m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			if ((i >> j) & 1)
				res[j].push_back(i);
	
	int k = 0;
	for (auto& i : res)
		k = max(k, (int)i.size());

	cout << m  << ' ' << k << '\n';
	for (auto& i : res)
	{
		cout << i.size() << ' ';
		for (auto& j : i)
			cout << j + 1 << ' ';
		cout << '\n';
	}

	return 0;
}