#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	double t = clock();

	srand(time(0));

	vector<unsigned int> res;

	int n, k; //n = 1e8; k = 200000;
	cin >> n >> k;
	unsigned int xpp, xp, a, b, c; //xpp = rand(); xp = rand(); a = rand(); b = rand(); c = rand();
	cin >> xpp >> xp >> a >> b >> c;

	long long l = (1 << 31), r = 0;
	{
		unsigned int xppt = xpp, xpt = xp, m = r - (r - l) * 1ll * (k - res.size()) / (n - res.size() + 1) - 10;
		for (int i = 0; i < n; ++i)
		{
			unsigned int x = (((a * xppt + b * xpt + c) << 1) >> 1);
			xppt = xpt; xpt = x;
			l = min(l, (long long)(x));
			r = max(r, (long long)(x + 1));
		}
	}

	while (res.size() < k)
	{
		unsigned int xppt = xpp, xpt = xp;
		long long m = max(r - (r - l) * 1ll * (k - res.size()) / (n - res.size() + 1) - 10, 0ll);
		for (int i = 0; i < n; ++i)
		{
			unsigned int x = (((a * xppt + b * xpt + c) << 1) >> 1);
			xppt = xpt; xpt = x;
			if (m <= int(x) && x < r)
				res.push_back(x);
		}
		r = m;
	}

	sort(res.begin(), res.end(), greater<unsigned int>());
	res.resize(k);

	for (auto& i : res)
		cout << i << ' ';
	cout << '\n';

	//cerr << (clock() - t) / CLOCKS_PER_SEC << '\n';

	return 0;
}