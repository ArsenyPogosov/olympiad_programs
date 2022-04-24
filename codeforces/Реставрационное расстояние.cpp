#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n, a, b, m; cin >> n >> a >> b >> m; m = min(m, a + b);
	vector<long long> h(n);
	for (auto& i : h) cin >> i;
	sort(h.begin(), h.end());
	long long s = accumulate(h.begin(), h.end(), 0ll), tek = 0, res = 1e18, M = s / n;
	for (long long i = 0; i < n - 1; ++i)
	{
		tek += h[i];
		long long L = h[i], R = h[i + 1], H, x, y, tres; ++i;
		H = L;
		if (L <= H && H <= R)
		{
			x = (H * i - tek); y = (s - tek - H * (n - i));
			if (x < y)
				tres = x * m + (y - x) * b;
			else
				tres = y * m + (x - y) * a;
			res = min(res, tres);
		}
		H = s / n;
		if (L <= H && H <= R)
		{
			x = (H * i - tek); y = (s - tek - H * (n - i));
			if (x < y)
				tres = x * m + (y - x) * b;
			else
				tres = y * m + (x - y) * a;
			res = min(res, tres);
		}
		H = (s + (n - 1)) / n;
		if (L <= H && H <= R)
		{
			x = (H * i - tek); y = (s - tek - H * (n - i));
			if (x < y)
				tres = x * m + (y - x) * b;
			else
				tres = y * m + (x - y) * a;
			res = min(res, tres);
		}
		H = R;
		if (L <= H && H <= R)
		{
			x = (H * i - tek); y = (s - tek - H * (n - i));
			if (x < y)
				tres = x * m + (y - x) * b;
			else
				tres = y * m + (x - y) * a;
			res = min(res, tres);
		}	
		--i;
	}
	cout << res << '\n';

	return 0;
}