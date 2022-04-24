#include <iostream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

vector<int> a, b, lowlog;
vector<vector<int>> sparseA, sparseB;
vector<pair<int, int>> winA, winB;

int itmin(int x, int y)
{
	if (b[x] <= b[y])
		return x;
	return y;
}

int itmax(int x, int y)
{
	if (a[x] >= a[y])
		return x;
	return y;
}

int minS(int l, int r)
{
	int k = lowlog[r - l + 1];
	return itmin(sparseB[k][l], sparseB[k][r - (1 << k) + 1]);
}

int maxS(int l, int r)
{
	int k = lowlog[r - l + 1];
	return itmax(sparseA[k][l], sparseA[k][r - (1 << k) + 1]);
}

void InitA(int l, int r)
{
	if (l == r)
		return;
	int it = maxS(l, r);
	winA[it] = { it - l, r - it };
	InitA(l, it - 1);
	InitA(it + 1, r);
}

void InitB(int l, int r)
{
	if (l == r)
		return;
	int it = minS(l, r);
	winB[it] = { l, r };
	InitB(l, it - 1);
	InitB(it + 1, r);
}

int Count(int x, int y)
{
	int l = x - min(winA[x].first, winB[y].first);
	int r = min(winA[x].second, winB[y].second) - y;
	if (l < 0 || r < 0)
		return 0;
	return (l + 1)*(r + 1);
}

int main()
{
	int n;
	cin >> n;
	a.resize(n);
	for (auto&i : a)
		cin >> i;
	b.resize(n);
	for (auto&i : b)
		cin >> i;
	lowlog.resize(n);
	for (int i = 0; (1 << i) < n; ++i)
		for (int j = (1 << i); j < min(1 << (i + 1), n); ++j)
			lowlog[j] = i;
	sparseA.resize(lowlog[n - 1] + 1, vector<int>(n));
	sparseB.resize(lowlog[n - 1] + 1, vector<int>(n));
	for (int i = 0; i < n; ++i)
	{
		sparseA[0][i] = i;
		sparseB[0][i] = i;
	}
	for (int i = 1; i < lowlog[n - 1]; ++i)
		for (int j = 0; j < n; ++j)
		{
			sparseA[i][j] = itmax(sparseA[i - 1][j],
				sparseA[i - 1][min(j + 1 << (i - 1), n - 1)]);
			sparseB[i][j] = itmin(sparseB[i - 1][j],
				sparseB[i - 1][min(j + 1 << (i - 1), n - 1)]);
		}
	InitA(0, n - 1);
	InitB(0, n - 1);
	vector<pair<int, int>> asort(n), bsort(n);
	for (int i = 0; i < n; ++i)
	{
		asort[i] = { a[i], i };
		bsort[i] = { b[i], i };
	}
	sort(asort.begin(), asort.end());
	sort(bsort.begin(), bsort.end());
	int ait = 0, bit = 0;
	while (ait < n && bit < n)
	{
		if (asort[ait].first < bsort[bit].first)
		{
			++ait;
			continue;
		}
		if (asort[ait].first > bsort[bit].first)
		{
			++bit;
			continue;
		}
	}

	return 0;
}