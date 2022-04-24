#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	srand(time(0));
	int n, a, b; cin >> n >> a >> b;
	vector<vector<double>> res(n + 1, vector<double>(n * 6 + 1));
	res[0][0] = 1;
	for (int i = 1; i <= n; ++i)
		for (int j = 0; j <= n * 6; ++j)
			for (int k = 1; k <= min(6, j); ++k)
				res[i][j] += res[i - 1][j - k] / 6;
	double ans = 0;
	for (int i = a; i <= b; ++i) ans += res[n][i];
	cout << fixed << setprecision(6) << ans << '\n';

	return 0;
}