#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long tc = 100;

long long m, k;
vector<vector<long long>> t;

bool check(long long y, long long i)
{
	for (long long j = 0; j < m; ++j)
	{
		long long td;
		if (y < k - 1)
			td = t[y + 1][j] - t[y][i];
		else
			td = t[y][i] - t[y - 1][j];
		if (td < 0) continue;

		bool flag = true;
		for (long long abc = 0; abc < tc; ++abc)
		{
			long long l = rand() % k;

			if (find(t[l].begin(), t[l].end(), t[y][i] + (l - y) * td) == t[l].end())
			{
				flag = false;
				break;
			}
		}

		if (flag)
			return true;
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> m >> k;
	t.resize(k, vector<long long>(m));
	for (auto& i : t)
	{
		for (auto& j : i)
			cin >> j;
		sort(i.begin(), i.end());
	}

	vector<long long> dd(3);
	dd[0] = accumulate(t[1].begin(), t[1].end(), 0ll) - accumulate(t[0].begin(), t[0].end(), 0ll);
	dd[1] = accumulate(t[2].begin(), t[2].end(), 0ll) - accumulate(t[1].begin(), t[1].end(), 0ll);
	dd[2] = accumulate(t[3].begin(), t[3].end(), 0ll) - accumulate(t[2].begin(), t[2].end(), 0ll);
	sort(dd.begin(), dd.end());
	long long d = dd[1];

	vector<long long> yy;
	for (long long i = 0; i < k; ++i)
	{
		long long h1 = -1, h2 = -1;
		if (i > 0)
			h1= -accumulate(t[i - 1].begin(), t[i - 1].end(), 0ll) + accumulate(t[i].begin(), t[i].end(), 0ll);
		if (i < k - 1)
			h2 = accumulate(t[i + 1].begin(), t[i + 1].end(), 0ll) - accumulate(t[i].begin(), t[i].end(), 0ll);
		if (i == 0 && h2 != d)
			yy.push_back(i);
		if (0 < i && i < k - 1 && h1 != d && h2 != d)
			yy.push_back(i);
		if (i == k - 1 && h1 != d)
			yy.push_back(i);
	}
	
	long long y;
	if (yy.size() == 1)
		y = yy[0];
	else
		y = (yy[0] ? yy[0] : yy[1]);

	long long add;
	if (y < m - 1)
		add = -accumulate(t[y + 1].begin(), t[y + 1].end(), 0ll) + accumulate(t[y].begin(), t[y].end(), 0ll);
	else
		add = accumulate(t[y].begin(), t[y].end(), 0ll) - accumulate(t[y - 1].begin(), t[y - 1].end(), 0ll);
	add -= d;
	add = -add;

	vector<long long> ord(m);
	iota(ord.begin(), ord.end(), 0);
	random_shuffle(ord.begin(), ord.end());
	for (auto&i: ord)
	{
		t[y][i] += add;
		if (check(y, i))
		{
			cout << y << ' ' << t[y][i] << '\n';
			return 0;
		}
		t[y][i] -= add;
	}

	return 0;
}