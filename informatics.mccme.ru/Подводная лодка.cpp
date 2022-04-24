#include <stdio.h>
#include <vector>
#include <deque>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

int hPref[2001][2001], bLeft[2001][2001], bUp[2001][2001], bRight[2001][2001], bDown[2001][2001], bLpart[2001][2001], bRpart[2001][2001];

inline int dist(int i, int j1, int j2)
{
	if (j2 - 2 < j1) return 0;
	return hPref[i][j2 - 1] - hPref[i][j1];
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int h, w, k;
	scanf("%d", &k);
	int c[27];
	for (int i = 0; i < k; ++i) scanf("%d", &c[i]);
	scanf("%d", &h);
	scanf("%d", &w);
	//vector<vector<int>> map(2001, vector<int>(2001));
	int map[2001][2001];
	for (int i = 0; i < h; ++i)
	{
		char hlp;
		scanf("%c", &hlp);
		for (int j = 0; j < w; ++j)
		{
			scanf("%c", &hlp);
			map[i][j] = c[hlp - 'a'];
		}
	}

	//hPref.resize(h, vector<int>(w));
	for (int i = 0; i <= h - 1; ++i)
	{
		hPref[i][0] = map[i][0];
		for (int j = 1; j <= w - 1; ++j)
			hPref[i][j] = hPref[i][j - 1] + map[i][j];
	}
	//bLeft.resize(h, vector<int>(w));
	for (int i = 0; i <= h - 1; ++i)
	{
		bLeft[i][0] = map[i][0];
		for (int j = 1; j <= w - 1; ++j)
			if (bLeft[i][j - 1] > 0)
				bLeft[i][j] = map[i][j] + bLeft[i][j - 1];
			else
				bLeft[i][j] = map[i][j];
	}
	//bUp.resize(h, vector<int>(w));
	for (int i = 0; i <= w - 1; ++i)
	{
		bUp[0][i] = map[0][i];
		for (int j = 1; j <= h - 1; ++j)
			if (bUp[j - 1][i] > 0)
				bUp[j][i] = map[j][i] + bUp[j - 1][i];
			else
				bUp[j][i] = map[j][i];
	}
	//bRight.resize(h, vector<int>(w));
	for (int i = 0; i <= h - 1; ++i)
	{
		bRight[i][w - 1] = map[i][w - 1];
		for (int j = w - 2; j >= 0; --j)
			if (bRight[i][j + 1] > 0)
				bRight[i][j] = map[i][j] + bRight[i][j + 1];
			else
				bRight[i][j] = map[i][j];
	}
	//bDown.resize(h, vector<int>(w));
	for (int i = 0; i <= w - 1; ++i)
	{
		bDown[h - 1][i] = map[h - 1][i];
		for (int j = h - 2; j >= 0; --j)
			if (bDown[j + 1][i] > 0)
				bDown[j][i] = map[j][i] + bDown[j + 1][i];
			else
				bDown[j][i] = map[j][i];
	}
	//bLpart.resize(h, vector<int>(w));
	for (int i = 0; i <= h - 1; ++i)
		for (int j = 0; j <= w - 2; ++j)
			bLpart[i][j] = bLeft[i][j] + bUp[i][j] - map[i][j];
	//bRpart.resize(h, vector<int>(w));
	for (int i = 0; i <= h - 1; ++i)
		for (int j = 1; j <= w - 1; ++j)
			bRpart[i][j] = bUp[i][j] + bRight[i][j] + bDown[i][j] - map[i][j] * 2;

	int best = -1000000000;
	for (int i = 0; i <= h - 1; ++i)
	{
		deque<int> bR;
		for (int j = 1; j <= w - 1; ++j)
		{
			while (!bR.empty() && bRpart[i][bR.back()] + dist(i, 0, bR.back()) <= bRpart[i][j] + dist(i, 0, j))
				bR.pop_back();
			bR.push_back(j);
		}
		for (int j = 0; j <= w - 2; ++j)
		{
			while (!bR.empty() && bR.front() <= j)
				bR.pop_front();
			best = max(best, bLpart[i][j] + dist(i, j, bR.front()) + bRpart[i][bR.front()]);
		}
	}

	printf("%d", best);

	return 0;
}