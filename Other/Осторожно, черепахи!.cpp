#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main()
{
	ifstream cin("fence.in");
	ofstream cout("fence.out");

	int n; cin >> n;
	if (n == 0)
	{
		cout << "0.00\n";
		return 0;
	}

	vector<int> x(n), y(n);
	for (int i = 0; i < n; ++i)
		cin >> x[i] >> y[i];

	float alp = 1 / 1e6 / 5, res = 1e18;
	for (float sn = 0; sn <= 1; sn += alp)
	{
		float cs = sqrt(1 - sn * sn);
		float mnx = 1e18, mny = 1e18, mxx = -1e18, mxy = -1e18;
		for (int i = 0; i < n; ++i)
		{
			float tx, ty;
			tx = x[i] * cs + y[i] * sn;
			ty = -x[i] * sn + y[i] * cs;
			mnx = min(mnx, tx);
			mny = min(mny, ty);
			mxx = max(mxx, tx);
			mxy = max(mxy, ty);
		}

		float l = max(mxx - mnx, mxy - mny);
		res = min(res, l);
	}
	res *= res;
	long long a = (long long)(res * 100) / 100;
	long long b = (long long)(res * 100) % 100;
	if (b < 10)
		cout << a << ".0" << b << '\n';
	else
		cout << a << "." << b << '\n';

	return 0;
}