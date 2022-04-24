#pragma GCC optimize ("O3")

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	double time = clock();

	int n, m, k; cin >> n >> m >> k;
	bool flip = n > m;
	if (flip)
		swap(n, m);

	vector<vector<char>> a(n, vector<char>(m));
	for (int i = 0; i < (flip ? m : n); ++i)
		for (int j = 0; j < (flip ? n : m); ++j)
		{
			char h; cin >> h; h -= '0';
			if (flip)
				a[j][i] = h;
			else
				a[i][j] = h;
		}

	int best = 0;
	int k1 = 0;
	vector<int> cnt(m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cnt[j] += a[i][j];

	for (int g = 0; g < (1 << n); ++g)
	{
		//if ((clock() - time) / CLOCKS_PER_SEC > 0.995)
		//	break;

		int mask = g ^ (g >> 1);
		if (g > 0)
		{
			int x = 31 - __builtin_clz(((g - 1) ^ ((g - 1) >> 1)) ^ mask);

			if ((mask >> x) & 1)
			{
				for (int j = 0; j < m; ++j)
					cnt[j] += (1 - a[x][j]) - a[x][j];

				++k1;
			}
			else
			{
				for (int j = 0; j < m; ++j)
					cnt[j] += -(1 - a[x][j]) + a[x][j];

				--k1;
			}
		}

		if (k1 > k) continue;

		vector<int> ncnt = cnt;

		nth_element(cnt.begin(), cnt.begin() + min(int(cnt.size()), k - k1 - 1), cnt.end());
		int cur = 0;
		for (int i = 0; i < m; ++i)
		{
			if (i < k - k1 && cnt[i] < n - cnt[i])
				cur += n - cnt[i];
			else
				cur += cnt[i];
		}

		best = max(best, cur);

		cnt = ncnt;
	}

	cout << best << '\n';

	return 0;
}