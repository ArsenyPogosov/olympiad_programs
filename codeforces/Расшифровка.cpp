#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m;
vector<int> a;
vector<vector<int>> sparseS, sparseB;

int log(int x)
{
	int h = 0;
	while ((1 << (h + 1)) < x) ++h;
	return h;
}

int Min(int i, int j)
{
	if (i > j) swap(i, j);
	if (a[i] <= a[j])
		return i;
	return j;
}

int Max(int i, int j)
{
	if (i > j) swap(i, j);
	if (a[i] > a[j])
		return i;
	return j;
}

void build()
{
	m = log(n) + 1;
	sparseS.resize(m, vector<int>(n));
	sparseB.resize(m, vector<int>(n));
	for (int i = 1; i < n; ++i)
	{
		sparseS[0][i] = i;
		sparseB[0][i] = i;
	}
	for (int i = 1; i < m; ++i)
		for (int j = 0; j < n; ++j)
		{
			sparseS[i][j] = Min(sparseS[i - 1][j], sparseS[i - 1][min(n - 1, j + (1 << (i - 1)))]);
			sparseB[i][j] = Max(sparseB[i - 1][j], sparseB[i - 1][min(n - 1, j + (1 << (i - 1)))]);
		}

}

int Minotr(int l, int r)
{
	int x = log(r - l + 1);
	return Min(sparseS[x][l], sparseS[x][r - (1 << x) + 1]);
}

int Maxotr(int l, int r)
{
	int x = log(r - l + 1);
	return Max(sparseB[x][l], sparseB[x][r - (1 << x) + 1]);
}

int ans(int l, int r)
{
	if (l > r) return 0;
	int L = Minotr(l, r), R = Maxotr(L, r);
	return ans(l, L - 1) + 1 + ans(R + 1, r);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	a.resize(n);
	for (auto& i : a) cin >> i;
	build();
	cout << ans(0, n - 1) << '\n';

	return 0;
}