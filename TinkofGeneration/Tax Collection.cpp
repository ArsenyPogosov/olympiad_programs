#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m, N;
vector<int> val;
vector<string> coord;

int findstart()
{
	vector<int> ps(N); partial_sum(val.begin(), val.end(), ps.begin());
	int sum = ps[N - 1];
	vector<int> smn(N); smn[N - 1] = ps[N - 1];
	for (int i = N - 2; i >= 0; --i) smn[i] = min(smn[i + 1], ps[i]);

	int pmn = 0;
	for (int i = 0; i < N; ++i)
	{
		if (sum - (i ? ps[i - 1] : 0) + pmn >= 0 && smn[i] - (i ? ps[i - 1] : 0) >= 0)
			return i;

		pmn = min(pmn, ps[i]);
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n >> m; N = n * m;
	vector<vector<int>> mass(n, vector<int>(m));

	for (auto& i : mass)
		for (auto& j : i)
			cin >> j;

	if (n % 2 == 1 && m % 2 == 1)
	{
		cout << "-1";
		return 0;
	}

	auto addpoint = [&](int i, int j) {
		coord.push_back(to_string(i + 1) + ' ' + to_string(j + 1));
		val.push_back(mass[i][j]);
	};
	if (n % 2 == 0)
	{
		for (int i = 0; i < n; i += 2)
		{
			for (int j = 1; j < m; ++j)
				addpoint(i, j);
			for (int j = m - 1; j > 0; --j)
				addpoint(i + 1, j);
		}
		for (int i = n - 1; i >= 0; --i)
			addpoint(i, 0);
	}
	else if (m % 2 == 0)
	{
		for (int j = 0; j < m; j += 2)
		{
			for (int i = 1; i < n; ++i)
				addpoint(i, j);
			for (int i = n - 1; i > 0; --i)
				addpoint(i, j + 1);
		}
		for (int j = m - 1; j >= 0; --j)
			addpoint(0, j);
	}

	int start = findstart();
	if (start == -1)
	{
		cout << -1 << '\n';
		return 0;
	}

	for (int i = 0; i < N; ++i)
		cout << coord[(start + i) % N] << '\n';

	return 0;
}