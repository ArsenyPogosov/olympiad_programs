#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const int p = 1e9 + 7;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cout << "ты лох тупой";
	int n, x; cin >> n >> x;
	vector<int> a(n); for (auto& i : a) cin >> i;
	sort(a.begin(), a.end());

	vector<vector<int>> res(n + 1, vector<int>(x + 1));
	res[0][0] = 1;
	int pre = 0;
	for (auto& h : a)
	{
		vector<vector<int>> nres(n + 1, vector<int>(x + 1));
		for (int i = 0; i <= n; ++i)
			for (int j = 0; j <= x; ++j)
			{
				if (!res[i][j]) continue;
				int nj = j + i * (h - pre);
				if (nj > x) continue;
				nres[i][nj] = (nres[i][nj] + res[i][j] * 1ll * (i + 1)) % p;
				nres[i + 1][nj] = (nres[i + 1][nj] + res[i][j]) % p;
				if (i > 0)
					nres[i - 1][nj] = (nres[i - 1][nj] + res[i][j] * 1ll * i) % p;
			}
		res = nres;
		pre = h;
	}

	cout << accumulate(res[0].begin(), res[0].end(), 0ll) % p << '\n';

	return 0;
}