#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const int INF = 1e9;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<vector<int>> a(n, vector<int>(n));
	for (auto& i : a)
		for (auto& j : i)
			cin >> j;
	vector<int> res(n - 1);
	res[0] = a[0][1];
	for (int i = 2; i < n; ++i)
	{
		res[i - 1] = INF;
		for (int j = 0; j < i - 1; ++j)
			res[i - 1] = min(res[i - 1], res[j] + a[j][i]);
		for (int j = 0; j < i - 1; ++j)
			res[j] += a[i - 1][i];
	}
	cout << *min_element(res.begin(), res.end()) << '\n';

	return 0;
}