#include <iostream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <cmath>
//#include <string>
using namespace std;

vector<int> LCS(const vector<int>& A, const vector<int>& B, const vector<int>& C)
{
	int n = A.size(), m = B.size(), l = C.size();
	vector<vector<vector<int>>> dp;
	vector<vector<vector<vector<int>>>> parent;
	dp.resize(n + 1, vector<vector<int>>(m + 1, vector<int>(l + 1)));
	parent.resize(n + 1, vector<vector<vector<int>>>(m + 1, vector<vector<int>>(l + 1, vector<int>(3, -1))));

	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			for (int k = 1; k <= l; ++k)
			{
				if ((A[i - 1] == B[j - 1]) && (B[j - 1] == C[k - 1]))
				{
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
					parent[i][j][k] = { i - 1, j - 1, k - 1 };
				}
				else
				{
					dp[i][j][k] = max(max(dp[i][j][k - 1], dp[i][j - 1][k]), dp[i - 1][j][k]);
					if (dp[i][j][k] == dp[i][j][k - 1]) parent[i][j][k] = { i, j, k - 1 };
					if (dp[i][j][k] == dp[i][j - 1][k]) parent[i][j][k] = { i, j - 1, k };
					if (dp[i][j][k] == dp[i - 1][j][k]) parent[i][j][k] = { i - 1, j, k };
				}
			}

	vector<int> ans;
	ans.reserve(dp[n][m][l]);
	vector<int> it = { n, m, l };
	while (it != vector<int>{-1, -1, -1})
	{
		if (parent[it[0]][it[1]][it[2]] == vector<int>{it[0] - 1, it[1] - 1, it[2] - 1})
			ans.push_back(A[it[0] - 1]);
		it = parent[it[0]][it[1]][it[2]];
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

int main()
{
	int n;
	cin >> n;
	vector<int> A(n);
	for (auto&i : A) cin >> i;
	int m;
	cin >> m;
	vector<int> B(m);
	for (auto&i : B) cin >> i;
	int l;
	cin >> l;
	vector<int> C(l);
	for (auto&i : C) cin >> i;

	vector<int> res = LCS(A, B, C);
	for (auto&i : res)
		cout << i << ' ';

	system("pause");
	return 0;
}