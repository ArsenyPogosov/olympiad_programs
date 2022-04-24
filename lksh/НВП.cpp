#include <iostream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

const int INF = 1000000000;

int main()
{
	int n, a, k, b, m;
	cin >> n >> a >> k >> b >> m;
	vector<int> mass(n);
	mass[0] = a;
	for (int i = 1; i < n; ++i)
		mass[i] = (mass[i - 1] * k + b) % m;

	vector<int> dp(n + 1, INF);
	dp[0] = -INF;
	for (int i = 0; i < n; ++i)
	{
		auto it = lower_bound(dp.begin(), dp.end(), mass[i]);
		*it = mass[i];
	}
	for (int i = n; i > 0; --i)
		if (dp[i] < INF)
		{
			cout << i;
			break;
		}

	return 0;
}