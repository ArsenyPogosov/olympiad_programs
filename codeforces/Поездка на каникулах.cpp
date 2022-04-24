//source: 
//status: coding

#include <bits/stdc++.h>
using namespace std;
#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("trains.in");
ofstream fout("trains.out");
#define cin fin
#define cout fout
#endif
#pragma endregion

int n, m, k, N;
vector<int> a;
vector<vector<int>> amm;

void bamm()
{
	int nn = n; N = 0;
	while (nn > 0)
	{
		nn = (nn >> 1);
		++N;
	}
	N += 2;
	amm.assign(n, vector<int>(N, -1));
	for (int i = 0; i < n; ++i)
		amm[i][0] = a[i];
	for (int j = 1; j < N; ++j)
		for (int i = 0; i < n; ++i)
		{
			if (amm[i][j - 1] == -1)
				amm[i][j] = -1;
			else
				amm[i][j] = amm[amm[i][j - 1]][j - 1];
		}
}

int ans(int a, int b)
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int count = 0;
	int d = N - 1;
	while (d >= 0)
	{
		while (d >= 0 && amm[a][d] == -1)
		{
			--d;
		}
		if (d < 0) return -1;
		bool flag = false;
		while (d >= 0 && amm[a][d] > b)
		{
			flag = true;
			--d;
		}
		if (amm[a][d] == b)
			return count + (1 << d);
		if (d == -1 && flag) 
			return count + 1;
		else
		{
			a = amm[a][d];
			count += (1 << d);
		}
	}
}

int main()
{
	cin >> n >> m >> k;
	vector<vector<pair<int, int>>> booked(k);
	for (int i = 0; i < m; ++i)
	{
		int a, b, c; cin >> a >> b >> c;
		booked[c - 1].push_back({ a - 1, b - 1 });
	}
	vector<pair<int, int>> free;
	for (auto& i : booked)
	{
		sort(i.begin(), i.end());
		int f = 0;
		for (auto& j : i)
		{
			free.push_back({ f, j.first });
			f = j.second;
		}
		free.push_back({ f, n - 1});
	}
	sort(free.begin(), free.end());
	a.assign(n, -1);
	int best = -1;
	int it = 0;
	for (int i = 0; i < n; ++i)
	{
		while (it < free.size() && free[it].first <= i)
		{
			best = max(best, free[it].second); 
			++it;
		}
		if (best > i)
			a[i] = best;
	}
	int q; cin >> q;
	bamm();
	for (int i = 0; i < q; ++i)
	{
		int a, b; cin >> a >> b;
		cout << ans(a - 1, b - 1) << '\n';
	}

	return 0;
}