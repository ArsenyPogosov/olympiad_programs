#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int m = 20;
vector<int> lg;

vector<vector<int>> stmin, stmax;

void initstmin(vector<int>& a)
{
	int n = a.size();
	stmin.assign(m, vector<int>(n));
	stmin[0] = a;
	for (int i = 1; i < m; ++i)
		for (int j = 0; j < n; ++j)
			stmin[i][j] = min(stmin[i - 1][j], stmin[i - 1][min(n - 1, j + (1 << (i - 1)))]);
}
void initstmax(vector<int>& a)
{
	int n = a.size();
	stmax.assign(m, vector<int>(n));
	stmax[0] = a;
	for (int i = 1; i < m; ++i)
		for (int j = 0; j < n; ++j)
			stmax[i][j] = max(stmax[i - 1][j], stmax[i - 1][min(n - 1, j + (1 << (i - 1)))]);
}

int minlr(int l, int r)
{
	return min(stmin[lg[r - l]][l], stmin[lg[r - l]][r - (1 << lg[r - l])]);
}

int maxlr(int l, int r)
{
	return max(stmax[lg[r - l]][l], stmax[lg[r - l]][r - (1 << lg[r - l])]);
}

int main()
{
	double t = clock();

	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	freopen("e.in", "r", stdin);
	freopen("e.out", "w", stdout);

	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];

	lg.resize(n + 1);
	for (int i = 2; i <= n; ++i)
		lg[i] = lg[i / 2] + 1;

	initstmin(a);
	initstmax(a);

	int m; cin >> m;
	while (m--)
	{
		int k; cin >> k;
		int bl = 0, br = 0;
		for (int l = 0, r = 0; r < n; ++l)
		{
			for (; r <= l || (r < n && maxlr(l, r + 1) - minlr(l, r + 1) <= k); ++r);

			if (r - l > br - bl)
			{
				bl = l;
				br = r;
			}
		}

		cout << bl + 1 << ' ' << br << '\n';
	}

	return 0;
}