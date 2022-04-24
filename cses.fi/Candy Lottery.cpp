#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	vector<double> res(k + 1, 1.0 / k); res[0] = 0;
	for (int i = 1; i < n; ++i)
	{
		vector<double> nres(k + 1);
		for (int x = 1; x <= k; ++x)
			for (int y = 1; y <= k; ++y)
				nres[max(x, y)] += res[x] / k;
		res = nres;
	}
	double ans = 0;
	for (int i = 1; i <= k; ++i) ans += res[i] * i;
	cout << fixed << setprecision(6) << ans << '\n';

	return 0;
}