#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long p = 1e9 + 7;

int main()
{
	long long n; cin >> n;
	vector<long long> res(max(n + 1, 10ll), 0);
	vector<long long> ress(max(n + 1, 10ll), 0);
	res[0] = 1; ress[0] = 1;
	res[1] = 3; ress[1] = 2;
	res[2] = 6; ress[2] = 4;
	/*res[0] = 1; ress[0] = 1;
	res[1] = 1; ress[1] = 2;
	res[2] = 4; ress[2] = 4;*/
	for (long long i = 3; i <= n; ++i)
	{
		res[i] = res[i - 1] + res[i - 2] * 3 + res[i - 3];
		res[i] %= p;
		ress[i] = ress[i - 1] + res[i - 2] + ress[i - 2] + ress[i - 3];
		ress[i] %= p;
	}
	ress[1] = 1;
	cout << ress[n] << '\n';

	return 0;
}