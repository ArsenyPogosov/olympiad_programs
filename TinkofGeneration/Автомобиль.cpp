#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long p = 1e9 + 7;
const long long div2 = (p + 1) / 2;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long n, m, k; cin >> n >> m >> k;

	vector<long long> rmult(n, 1), cmult(m, 1), rlist, clist;
	vector<bool> rwas(n), cwas(m);

	long long sum = (n * m % p) * (n * m % p + 1) % p * div2 % p;
	while (k--)
	{
		char h; long long x, y;
		cin >> h >> x >> y; --x;
		if (h == 'R')
		{
			long long tsum = m * (x * m * 2 % p + m + 1) % p * div2 % p * rmult[x] % p;
			for (auto& i : clist)
				tsum = ((tsum + (x * m % p + i + 1) * rmult[x] % p * (cmult[i] - 1)) % p + p) % p;
			sum = ((sum + tsum * (y - 1)) % p + p) % p;
			if (!rwas[x]) rlist.push_back(x);
			rwas[x] = true;
			rmult[x] = rmult[x] * y % p;
		}
		if (h == 'S')
		{
			long long tsum = ((x + 1) * n % p + (n * (n - 1) % p * div2 % p) * m % p) * cmult[x] % p;
			for (auto& i : rlist)
				tsum = ((tsum + (i * m % p + x + 1) * cmult[x] % p * (rmult[i] - 1)) % p + p) % p;
			sum = ((sum + tsum * (y - 1)) % p + p) % p;
			if (!cwas[x]) clist.push_back(x);
			cwas[x] = true;
			cmult[x] = cmult[x] * y % p;
		}
	}

	cout << ((sum % p) + p) % p << '\n';

	return 0;
}