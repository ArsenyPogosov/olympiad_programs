#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> x(n), y(n);
	for (auto& i : x) cin >> i;
	for (auto& i : y) cin >> i;
	double dt = 1e18, kt, bt;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
		{
			double d = 0, k, b;
			k = (x[i] - x[j]) * 1.0 / (y[i] - y[j]);
			b = x[i] - k * y[i];
			for (int l = 0; l < n; ++l)
				d += abs(x[l] - k * y[l] - b);
			if (dt > d)
			{
				dt = d;
				kt = k;
				bt = b;
			}
		}
	cout << fixed << setprecision(18) << dt << ' ' << kt << ' ' << bt <<'\n';

	return 0;
}