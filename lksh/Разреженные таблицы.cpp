#include <iostream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

vector<vector<int>> sparseTable;
vector<int> lowerLog;
int n, m, a;

int minST(int l, int r)
{
	if (l > r)
		swap(l, r);
	int k = lowerLog[r - l];
	return min(sparseTable[k][l], sparseTable[k][r - (1 << k) + 1]);
}

int main()
{
	cin >> n >> m >> a;
	lowerLog.resize(n);
	for (int i = 0; 1 << i < n; ++i)
		for (int j = 1 << i; j < min(1 << (i + 1), n); ++j)
			lowerLog[j] = i;
	sparseTable.resize(lowerLog[n - 1] + 1, vector<int>(n));
	for (auto&i : sparseTable[0])
	{
		i = a;
		a = (23 * a + 21563) % 16714589;
	}
	for (int i = 1; i <= lowerLog[n - 1]; ++i)
		for (int j = 0; j < n; ++j)
			sparseTable[i][j] = min(sparseTable[i - 1][j],
				sparseTable[i - 1][min(j + (1 << (i - 1)), n - 1)]);
	int u, v, ans;
	cin >> u >> v;
	ans = minST(u - 1, v - 1);
	for (int i = 2; i <= m; ++i)
	{
		u = ((17 * u + 751 + ans + 2 * (i - 1)) % n) + 1;
		v = ((13 * v + 593 + ans + 5 * (i - 1)) % n) + 1;
		ans = minST(u - 1, v - 1);
	}
	cout << u << ' ' << v << ' ' << ans;

	return 0;
}