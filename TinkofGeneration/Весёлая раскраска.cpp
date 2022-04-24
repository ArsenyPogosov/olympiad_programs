#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	vector<long long> res2{             1,  0, 1,             1, 0, 0,  0,             1 };
	vector<long long> res3{ (1 << 18) - 1, 16, 3, (1 << 12) - 1, 2, 1, 16, 178956971 - 1 };

	vector<vector<long long>> res(30, vector<long long>(3));
	res[1][1] = 1;
	for (int i = 2; i < 30; ++i)
		for (int j = 0; j < 3; ++j)
			for (int k = 0; k < 3; ++k)
			{
				if (j == k) continue;
				if (i == 29 && k == 0) continue;
				res[i][k] += res[i - 1][j];
			}
	//cout << res[29][0] + res[29][1] + res[29][2] << '\n';

	int n; long long k; cin >> n >> k; --n;
	//if (n == 6) return 1;
	cout << k * (k - 1) * res2[n] + k * (k - 1) * (k - 2) * res3[n] << '\n';

	return 0;
}