#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long p = 1e9 + 7;

long long n;
vector<long long> tenp;

vector<vector<long long>> cnt(string s)
{
	vector<vector<long long>> res(n, vector<long long>(10));
	vector<long long> beginp(n), endp(n);
	beginp[0] = 1;
	for (long long i = 0; i < n - 1; ++i)
		beginp[i + 1] = ((beginp[i] - 1) * 10 + (s[i] - '0') + 1) % p;
	endp[n - 1] = 1;
	for (long long i = n - 1; i > 0; --i)
		endp[i - 1] = ((s[i] - '0') * tenp[i] + endp[i]) % p;
	for (long long i = 0; i < n; ++i)
	{
		for (long long j = 0; j < s[i] - '0'; ++j)
			res[i][j] = (beginp[i] * tenp[i]) % p;
		res[i][s[i] - '0'] = ((beginp[i] - 1) * tenp[i] + 1 * endp[i]) % p;
		for (long long j = s[i] - '0' + 1; j < 10; ++j)
			res[i][j] = ((beginp[i] - 1) * tenp[i]) % p;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string a, b; cin >> a >> b;
	n = b.size();
	a = string(n - a.size(), '0') + a;
	tenp.resize(n); tenp[n - 1] = 1;
	for (long long i = n - 2; i >= 0; --i)
		tenp[i] = (tenp[i + 1] * 10) % p;
	vector<vector<long long>> count = cnt(b), tek = cnt(a);
	for (long long i = 0; i < n; ++i)
		for (long long j = 0; j < 10; ++j)
			count[i][j] -= tek[i][j];
	for (long long i = 0; i < n; ++i)
		++count[i][a[i] - '0'];
	long long res = 0;
	for (long long k = 0; k < n; ++k)
	{
		for (long long i = 0; i < 9; ++i)
			for (long long j = i + 1; j < 10; ++j)
				res += (((j - i) * count[k][i] * count[k][j]) % p) * 2;
	}
	res %= p;
	cout << res << '\n';

	return 0;
}