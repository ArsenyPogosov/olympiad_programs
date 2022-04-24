#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m;
vector<vector<int>> res;

void add(vector<int> &h)
{
	vector<vector<int>> ord(n + 1);
	for (int i = 0; i < m; ++i) ord[h[i]].push_back(i);
	vector<int> sz(m, 0);
	for (int i = n; i >= 1; --i)
		for (auto& j : ord[i])
		{
			int l = (j > 0 ? sz[j - 1] : 0), r = (j < m - 1 ? sz[j + 1] : 0);
			sz[j - l] = sz[j + r] = l + 1 + r;
			if (l > 0) --res[i - 1][l - 1];
			if (r > 0) --res[i - 1][r - 1];
			++res[i - 1][l + r + 1 - 1];
		}
}

void collapse()
{
	for (int i = n - 1; i > 0; --i)
		for (int j = 0; j < m; ++j)
			res[i - 1][j] += res[i][j];
	for (int i = 0; i < n; ++i)
		for (int j = m - 2, cotr = res[i][m - 1]; j >= 0; --j)
		{
			cotr += res[i][j]; 
			res[i][j] = res[i][j + 1] + cotr;
		}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	res.resize(n, vector<int>(m));
	vector<int> h(m);
	for (int i = 0; i < n; ++i)
	{
		for (auto& j : h)
		{
			char x; cin >> x;
			j = (x == '.' ? j + 1 : 0);
		}
		add(h);
	}
	collapse();

	for (auto& i : res)
	{
		for (auto& j : i) cout << j << ' ';
		cout << '\n';
	}

	return 0;
}