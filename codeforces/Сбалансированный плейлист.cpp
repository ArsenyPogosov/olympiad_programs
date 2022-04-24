//source: https://codeforces.com/contest/1237/problem/D
//status: coding

#include <bits/stdc++.h>
using namespace std;
//#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif
#pragma endregion

const int INF = 100000000;

vector<int> a;
vector<vector<int>> st;
int n, m;

int logg(int n)
{
	int res = 0;
	while (n = n >> 1) ++res;
	return res;
}

void init()
{
	m = logg(n * 2);
	st.resize(m, vector<int>(n * 2));
	for (int i = 0; i < n * 2; ++i)
		st[0][i] = a[i];
	for (int i = 1; i < m; ++i)
		for (int j = 0; j < n * 2; ++j)
			st[i][j] = min(st[i - 1][j], st[i - 1][min(j + (1 << (i - 1)), n * 2 - 1)]);
}

int minn(int l, int r)
{
	int x = logg(r - l + 1);
	return min(st[x][l], st[x][r - (1 << x) + 1]);
}

int main()
{
	cin >> n;
	a.resize(n * 2);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		a[i + n] = a[i];
	}
	init();
	vector<int> fw(INF), ans(n * 2, INF);
	for (int i = 0; i < n * 2; ++i)
	{
		int l = i, r = n * 2;
		while (l + 1 < r)
		{
			int m = (l + r) / 2;
			if (minn(l, m) * 2 < a[i])
				r = m;
			else
				l = m;
		}
		if (r != n * 2)
			fw[i] = r;
	}
	for (int i = n * 2 - 2; i >= 0; --i)
		ans[i] = min(fw[i] - i, ans[i + 1] + 1);
	for (int i = 0; i < n; ++i)
		cout << ((ans[i] != n * 2) ? ans[i] : -1) << ' ';

	return 0;
}