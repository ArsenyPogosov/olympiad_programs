#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> x(n);
	for (auto& i : x) cin >> i;
	double res = 0;
	for (int i = 0; i < n - 1; ++i)
		for (int j = i + 1; j < n; ++j)
			res += double(min(x[i], x[j]) * (min(x[i], x[j]) - 1) / 2 + max(0, x[i] - x[j]) * x[j]) / x[i] / x[j];
	cout << fixed << setprecision(6) << res << '\n';

	return 0;
}