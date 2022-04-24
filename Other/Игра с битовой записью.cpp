#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long a = 134775813, c = 1;

const long long X = 100000000;

long long s;

long long next(long long curr)
{
	return (a * curr + c) % (1ll << 32);
}

long long random(long long r)
{
	long long res = ((s * r) >> 32);
	s = next(s);
	
	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n; n *= 2;
	vector<char> h(n);
	vector<int> t(n);
	for (int i = 0; i < n; ++i) cin >> h[i] >> t[i];

	int cnt = 0;
	double e = 0;
	vector<double> res; res.reserve(n / 2);
	for (int i = n - 1; i >= 0; --i)
	{
		e += (i < n - 1 ? t[i + 1] - t[i] : 0);

		if (h[i] == '+')
		{
			res.push_back(e);
			--cnt;
		}
		if (h[i] == '-')
		{
			++cnt;
			e *= (1 - 1.0 / cnt);
		}
	}

	for (int i = res.size() - 1; i >= 0; --i)
		cout << fixed << setprecision(16) << res[i] << '\n';

	return 0;
}