#include <iostream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
#include <string>
using namespace std;

const int p = 1000000007;

bool check(int a, int b, int c, int d)
{
	return 0 <= a && a <= 9 && 0 <= b && b <= 9 && a != c && b != d;
}

int main()
{
	string s;
	cin >> s;
	int n = s.size();
	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(10, vector<int>(2, 0)));
	for (int i = 0; i <= 9; ++i)
	{
		int s1 = s[0] - '0';
		if (i <= s1)
			dp[1][i][0] = 1;
		if (n >= 2)
		{
			int s2 = s1 + (s[1] - '0') * 10;
			if (s2 - i <= 9)
				dp[1][i][1] = 1;
		}
	}
	for (int l = 2; l <= n; ++l)
		for (int i = 0; i <= 9; ++i)
			for (int j = 0; j <= 9; ++j)
			{
				if (check(i, s[l - 1] - '0' - i, j, ))
			}

	return 0;
}