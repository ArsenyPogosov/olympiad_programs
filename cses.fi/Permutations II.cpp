#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const int p = 1e9 + 7;

int main()
{
	int n; cin >> n;
	/*deque<int> res{ 1, 1, 0, 0 };
	for (long long i = 4; i <= n; ++i)
	{
		int nval = ((res[3] * (i + 1) - res[2] * (i - 2) - res[1] * (i - 5) + res[0] * (i - 3)) % p + p) % p;
		res.pop_front(); res.push_back(nval);
	}
	if (n < 4)
		cout << res[n] << '\n';
	else
		cout << res[3] << '\n';*/
	vector<int> res(n + 1); 
	res[0] = 1; res[1] = 1; res[2] = 0; res[3] = 0;
	for (int i = 4; i <= n; ++i)
	{
		res[i] += res[i - 1] * (i - 2);
		res[i] += res[i - 3] * ((i - 3) * 2 * (i - 4) + 2);
		int var = (i - 3) * 2 + 1;
		for (int j = 2; j * 2 < i; ++j)
		{
			int ost = i - 1 - j * 2;
			res[i] += res[ost] * ((var * (ost + 1)) * 2 * (ost - 1) + var * 4);
			var *= ost * 2 + 1;
		}
		/*var = 2;
		for (int j = 2; j * 2 < i; ++j)
		{
			int ost = i - 1 - j * 2;
			res[i] -= res[ost] * ((var * (ost + 1)) * 2 * (ost - 1) + var * 4);
			var *= ost * 2 + 1;
		}*/
	}
	for (auto&i: res)
		cout << i << '\n';

	return 0;
}