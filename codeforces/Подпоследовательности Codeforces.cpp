#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long pow10(long long a)
{
	long long res = 1;
	for (int i = 0; i < 10; ++i) res *= a;
	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s = "codeforces";
	long long k; cin >> k;
	long long p = 1;
	while (pow10(p + 1) <= k) ++p;
	vector<int> res(10, p);
	long long count = pow10(p);
	for (int i = 0; i < 10; ++i)
		if (count >= k)
			break;
		else
		{
			++res[i];
			count = count / (p) * (p + 1);
		}
	for (int i = 0; i < 10; ++i)
		for (int j = 0; j < res[i]; ++j)
			cout << s[i];
	cout << '\n';

	return 0;
}