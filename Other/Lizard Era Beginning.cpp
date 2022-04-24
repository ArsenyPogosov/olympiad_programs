#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

template <class T1, class T2>
struct pair_hash {
	size_t operator () (const pair<T1, T2>& p) const {
		auto h1 = hash<T1>{}(p.first);
		auto h2 = hash<T2>{}(p.second);
		return hash<string>()(to_string(h1) + ',' + to_string(h2));
	}
};

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	vector<string> symb{ "MW", "LW", "LM" };

	int n; cin >> n;
	vector<vector<int>> d(n, vector<int>(3));
	for (auto& i : d)
		cin >> i[0] >> i[1] >> i[2];

	if (n == 1)
	{
		int cnt = 0;
		for (int k = 0; k < 3; ++k)
			cnt += d[0][k] == 0;
		for (int i = 0; i < 3; ++i)
		{
			if (cnt - (d[0][i] == 0) == 2)
			{
				cout << symb[i] << '\n';
				return 0;
			}
		}

		cout << "Impossible\n";
		return 0;
	}

	vector<uint64_t> pow3(n);
	pow3[0] = 1;
	for (int i = 1; i < n; ++i)
		pow3[i] = pow3[i - 1] * 3;

	int m = n / 2;
	unordered_map<pair<int, int>, pair<int, uint64_t>, pair_hash<int, int>> vars;
	for (uint64_t mask = 0; mask < pow3[m]; ++mask)
	{
		int cnt[3]; cnt[0] = cnt[1] = cnt[2] = 0;
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < 3; ++j)
				if (mask / pow3[i] % 3 != j)
					cnt[j] += d[i][j];

		cnt[1] -= cnt[0];
		cnt[2] -= cnt[0];

		if (vars.find({ cnt[1], cnt[2] }) == vars.end() || vars[{cnt[1], cnt[2]}].first < cnt[0])
			vars[{cnt[1], cnt[2]}] = { cnt[0], mask };
	}

	bool find = false;
	int bsum = 0;
	uint64_t bmask = 0;
	for (uint64_t mask = 0; mask < pow3[n - m]; ++mask)
	{
		int cnt[3]; cnt[0] = cnt[1] = cnt[2] = 0;
		for (int i = m; i < n; ++i)
			for (int j = 0; j < 3; ++j)
				if (mask / pow3[i - m] % 3 != j)
					cnt[j] += d[i][j];

		cnt[1] -= cnt[0];
		cnt[2] -= cnt[0];

		if (vars.find({ -cnt[1], -cnt[2] }) != vars.end())
		{
			int tsum = cnt[0] + vars[{-cnt[1], -cnt[2]}].first;
			int tmask = mask * pow3[m] + vars[{-cnt[1], -cnt[2]}].second;

			if (!find || tsum > bsum)
			{
				find = true;
				bsum = tsum;
				bmask = tmask;
			}
		}
	}
	
	if (!find)
		cout << "Impossible\n";
	else
	{
		for (int i = 0; i < n; ++i)
		{
			cout << symb[bmask / pow3[i] % 3] << '\n';
		}
	}

	return 0;
}
