#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	vector<int> p(n);
	for (auto& i : p)
	{
		char h; cin >> h;
		if (h == 'L') i = 0;
		if (h == 'R') i = 1;
	}
	vector<vector<int>> td; td.reserve(n + 5);
	int kmin = 0, kmax = 0;
	while (kmax < n * n + 5)
	{
		td.push_back({}); ++kmin;
		for (int i = 0; i + 1 < n;)
		{
			if ((p[i] == 1) && (p[i + 1] == 0))
			{
				p[i] = 0;
				p[i + 1] = 1;
				td[td.size() - 1].push_back(i + 1); ++kmax;
				i += 2;
			}
			else
				++i;
		}
		if (td[td.size() - 1].size() == 0) break;
	}
	if (td[kmin - 1].size() != 0)
	{
		cout << -1 << '\n';
		return 0;
	}
	--kmin;
	if (!((kmin <= k) && (k <= kmax)))
	{
		cout << -1 << '\n';
		return 0;
	}
	int sum = 0;
	for (int i = 0; i < kmin; ++i)
	{
		int hm = min(k - sum - (kmin - i - 1), int(td[i].size()));
		sum += hm;
		for (int j = 0; j < hm - 1; ++j)
			cout << "1 " << td[i][j] << '\n';
		cout << td[i].size() - hm + 1;
		for (int j = hm - 1; j < td[i].size(); ++j)
			cout << ' ' << td[i][j];
		cout << '\n';
	}

	return 0;
}