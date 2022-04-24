#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q; cin >> n >> q;
	vector<vector<int>> psforest(n + 1, vector<int>(n + 1));
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
		{
			char h; cin >> h;
			psforest[i][j] = (h == '*') + psforest[i - 1][j] + psforest[i][j - 1] - psforest[i - 1][j - 1];
		}
	while (q--)
	{
		int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
		cout << psforest[x2][y2] - psforest[x2][y1 - 1] - psforest[x1 - 1][y2] + psforest[x1 - 1][y1 - 1] << '\n';
	}

	return 0;
}