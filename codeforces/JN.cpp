//source: http://neerc.ifmo.ru/school/io/archive/20191019/problems-20191019-advanced.pdf
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

int g(int a, int b)
{
	return int(ceil(sqrt(a * b)));
}

int k(int a, int b)
{
	return int(floor(sqrt((a * a + b * b) / 2.0)));
}

int main()
{
	int a, b;
	cin >> a >> b;
	int count = 0, n = 2001;
	vector<vector<int>> dp(n, vector<int>(n, 1000000000));
	for (int i = 0; i < n; ++i)
		dp[i][i] = 0;
	for (int i = n - 1; i >= 0; --i)
		for (int j = i + 1; j < n; ++j)
			dp[i][j] = min(min(dp[g(i, j)][j], dp[k(i, j)][j]), min(dp[i][g(i, j)], dp[i][k(i, j)])) + 1;
	cout << dp[a][b];

	return 0;
}