#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<long long> pow10;

long long ans(long long n, int k = 18, bool f = true, int ban = -1)
{
	if (n == -1) return 0;
	if (k == -1) return 1;

	if (f) ban = -1;
	long long res = 0;
	int h = n / pow10[k];
	long long lolkek = ans(pow10[k] - 1, k - 1, f && (1 == 0), 1);
	for (int i = 0; i < h; ++i)
	{
		if (i == ban) continue;
		if (i == 0)
			res += ans(pow10[k] - 1, k - 1, f && (i == 0), i);
		else
			res += lolkek;
	}
	if (h != ban)
		res += ans(n - h * pow10[k], k - 1, f && (h == 0), h);

	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	pow10.resize(19);
	pow10[0] = 1;
	for (int i = 1; i < 19; ++i) pow10[i] = pow10[i - 1] * 10;

	long long a, b; cin >> a >> b;
	cout << ans(b) - ans(a - 1) << '\n';

	return 0;
}