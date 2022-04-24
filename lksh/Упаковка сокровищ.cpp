#include <iostream>
#include <iomanip>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

vector<pair<int, int>> N, Y;

double GetM(int w)
{
	double res = 0;
	for (auto& i : Y)
	{
		int gw = min(w, i.first);
		res += double(gw * i.second) / i.first;
		w -= gw;
		w = max(w, 0);
	}
	return res;
}

int main()
{
	int W, n;
	cin >> W >> n;
	N.reserve(n);
	Y.reserve(n);
	for (int i = 0; i < n; ++i)
	{
		int w, c;
		char h;
		cin >> w >> c >> h;
		if (h == 'N')
			N.push_back({ w, c });
		if (h == 'Y')
			Y.push_back({ w, c });
	}
	sort(Y.begin(), Y.end(), [](pair<int, int> a, pair<int, int> b) {
		return a.second * b.first > b.second * a.first;
	});
	double maxx = 0;
	int Nn = N.size();
	if (Nn != 0)
	{
		vector<vector<int>> dp(Nn, vector<int>(W + 1, 0));
		dp[0][N[0].first] = N[0].second;
		for (int i = 1; i < Nn; ++i)
			for (int j = 0; j <= W; ++j)
			{
				dp[i][j] = dp[i - 1][j];
				if (j >= N[i].first)
					dp[i][j] = max(dp[i][j], dp[i - 1][j - N[i].first] + N[i].second);
			}
		for (int i = 0; i <= W; ++i)
			maxx = max(maxx, double(dp[Nn - 1][i]) + GetM(W - i));
	}
	else
		maxx = GetM(W);
	cout << setprecision(20) << maxx;

	return 0;
}