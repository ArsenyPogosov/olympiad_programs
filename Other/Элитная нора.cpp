#pragma comment(linker, "/stack:20000000")

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const int N = 1000, M = 1000, K = N * M;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("burrow.in", "r", stdin);
	//freopen("burrow.out", "w", stdout);

	int n, m, k;
	cin >> n >> m >> k;

	int val[N * M];
	int a[N][M];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> a[i][j];

	int l = 0, r = 1e9 + 1, area = -1;
	while (l + 1 < r)
	{
		int curr = (l + r) / 2;
		int up[M];
		fill(up, up + M, 0);

		int mx = -1;
		deque<int> ord(m);
		iota(ord.begin(), ord.end(), 0);
		for (int i = 0; i < n; ++i)
		{
			deque<int> nord;
			for (int j = m - 1; j >= 0; --j)
			{
				if (a[i][ord[j]] >= curr)
				{
					++up[ord[j]];
					nord.push_front(ord[j]);
				}
				else
				{
					up[ord[j]] = 0;
					nord.push_back(ord[j]);
				}
			}
			ord = nord;

			vector<int> pit(m, -1);

			for (auto& j : ord)
			{
				int lit = (j > 0 ? pit[j - 1] : 0), rit = (j < m - 1 ? pit[j + 1] : m - 1);
				if (lit == -1) lit = j;
				if (rit == -1) rit = j;
				pit[lit] = rit;
				pit[rit] = lit;

				mx = max(mx, (rit - lit + 1) * up[j]);
				if (mx >= k) break;
			}
			if (mx >= k) break;
		}

		if (mx >= k)
		{
			l = curr;
			area = mx;
		}
		else
		{
			r = curr;
		}
	}

	int curr = l;
	vector<int> up(m, 0);

	int mx = -1;
	deque<int> ord(m);
	iota(ord.begin(), ord.end(), 0);
	for (int i = 0; i < n; ++i)
	{
		deque<int> nord;
		for (int j = m - 1; j >= 0; --j)
		{
			if (a[i][ord[j]] >= curr)
			{
				++up[ord[j]];
				nord.push_front(ord[j]);
			}
			else
			{
				up[ord[j]] = 0;
				nord.push_back(ord[j]);
			}
		}
		ord = nord;

		vector<int> pit(m, -1);

		for (auto& j : ord)
		{
			int lit = (j > 0 ? pit[j - 1] : 0), rit = (j < m - 1 ? pit[j + 1] : m - 1);
			if (lit == -1) lit = j;
			if (rit == -1) rit = j;
			pit[lit] = rit;
			pit[rit] = lit;

			mx = max(mx, (rit - lit + 1) * up[j]);
		}
	}

	cout << l << ' ' << mx << '\n';

	return 0;
}