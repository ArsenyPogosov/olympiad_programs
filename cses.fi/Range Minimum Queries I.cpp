#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
vector<int> a;

vector<int> mlog2;
void buildmlog2()
{
	mlog2.resize(n + 1);
	int res = 0;
	for (int i = 1; i <= n; ++i)
	{
		if ((1 << (res + 1)) <= i) ++res;
		mlog2[i] = res;
	}
}

int m;
vector<vector<int>> sparse;
void buildsparse()
{
	m = mlog2[n] + 1;
	sparse.resize(m, vector<int>(n));
	sparse[0] = a;
	for (int i = 1; i < m; ++i)
		for (int j = 0; j < n; ++j)
			sparse[i][j] = min(sparse[i - 1][j], sparse[i - 1][min(n - 1, j + (1 << (i - 1)))]);
}

int smin(int l, int r)
{
	int i = mlog2[r - l + 1];
	return min(sparse[i][l], sparse[i][r - (1 << i) + 1]);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int q; cin >> n >> q; a.resize(n);
	for (auto& i : a) cin >> i;
	buildmlog2();
	buildsparse();
	while (q--)
	{
		int l, r; cin >> l >> r;
		cout << smin(l - 1, r - 1) << '\n';
	}

	return 0;
}