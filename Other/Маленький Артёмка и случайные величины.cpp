#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<double> mn(n), mx(n);
	for (auto& i : mx) cin >> i;
	for (auto& i : mn) cin >> i;

	double p1 = 0, p2 = 0;
	vector<double> dp1(n), dp2(n);
	for (int i = 0; i < n; ++i)
	{
		// dp2 = min + max - dp1
		// dp1^2 + (p1-p2)dp1 + (max(1-p1)-min*p1) = 0
		double a = 1, b = p1 - p2 - mn[i] - mx[i], c = mx[i] * (1 - p1) - mn[i] * p1;
		dp1[i] = (-b + sqrt(max(b * b - 4 * a * c, 0.0))) / (2 * a);
		dp2[i] = mn[i] + mx[i] - dp1[i];
		p1 += dp1[i];
		p2 += dp2[i];
	}

	cout << fixed << setprecision(16);
	for (auto& i : dp1)
		cout << i << ' ';
	cout << '\n';
	for (auto& i : dp2)
		cout << i << ' ';
	cout << '\n';

	return 0;
}