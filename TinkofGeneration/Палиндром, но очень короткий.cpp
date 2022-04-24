#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string s, h;
	while (cin >> h) s += h;

	int n = s.size();
	vector<int> cntall('z' - 'a' + 1);
	for (auto& i : s) ++cntall[i - 'a'];

	long long res = 0;
	vector<int> cnt('z' - 'a' + 1);
	for (auto& i : s)
	{
		for (int j = 0; j < 'z' - 'a' + 1; ++j)
			res += cnt[j] * 1ll * (cntall[j] - cnt[j] - (i - 'a' == j));
		++cnt[i - 'a'];
	}

	cout << res << '\n';

	return 0;
}