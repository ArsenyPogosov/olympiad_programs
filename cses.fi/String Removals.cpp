#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const int p = 1e9 + 7;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s; cin >> s;
	int res = 0;
	vector<int> dp('z' - 'a' + 1);
	for (auto& i : s)
	{
		int h = i - 'a';
		res = (res - dp[h] + p) % p;
		dp[h] = (dp[h] + res + 1) % p;
		res = (res + dp[h]) % p;
	}
	cout << res << '\n';

	return 0;
}