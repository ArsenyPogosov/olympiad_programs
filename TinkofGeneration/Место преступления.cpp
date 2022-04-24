#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long INF = 1e18;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long n, k; double d; cin >> n >> d >> k;

	vector<char> missed(n);
	for (long long i = 0; i < k; ++i)
	{
		long long h; cin >> h;
		missed[h - 1] = true;
	}

	vector<double> x(n), y(n);
	for (long long i = 0; i < n; ++i)
		cin >> x[i] >> y[i];
	vector<double> len(n);
	for (long long i = 0; i < n; ++i)
		len[i] = sqrt((x[i] - x[(i + 1) % n]) * (x[i] - x[(i + 1) % n]) +
			(y[i] - y[(i + 1) % n]) * (y[i] - y[(i + 1) % n]));

	double res = 0, tl = 0, tr = 0;
	for (long long l = 0, r = 0; l < n;)
	{
		while (tl + len[r] <= d)
		{
			tl += len[r];
			if (missed[r])
				tr += len[r];
			r = (r + 1) % n;

			if (r == l)
			{
				cout << 0 << '\n';
				return 0;
			}
		}

		double add = 0;
		if (missed[r] && r != l) add = d - tl;
		res = max(res, tr + add);

		tl -= len[l];
		if (l == r)
		{
			r = (r + 1) % n;
			tl = 0;
			tr = 0;
		}
		else if (missed[l])
			tr -= len[l];

		++l;
	}
	tl = 0; tr = 0;
	for (long long l = n - 1, r = n - 1; l >= 0;)
	{
		while (tl + len[r] <= d)
		{
			tl += len[r];
			if (missed[r])
				tr += len[r];
			r = (r - 1 + n) % n;

			if (r == l)
			{
				cout << 0 << '\n';
				return 0;
			}
		}

		double add = 0;
		if (missed[r] && r != l) add = d - tl;
		res = max(res, tr + add);

		tl -= len[l];
		if (l == r)
		{
			r = (r - 1 + n) % n;
			tl = 0;
			tr = 0;
		}
		else if (missed[l])
			tr -= len[l];

		--l;
	}

	res = -res;
	for (long long i = 0; i < n; ++i)
		if (missed[i])
			res += len[i];

	//res = 1e6 + 1 / 1e6;
	cout << setprecision(8) << fixed << max(res, double(0 + 1/1e16)) << '\n';

	return 0;
}