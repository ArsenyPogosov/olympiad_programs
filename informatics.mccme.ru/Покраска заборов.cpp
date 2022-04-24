#include <iostream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

int n;
vector<vector<int>> squere;
vector<vector<int>> point;
vector<vector<int>> T;
vector<int> ySort, sqSort, used;

bool comX(int a, int b) { return point[a][0] < point[b][0]; }
bool comY(int a, int b) { return point[a][1] < point[b][1]; }
bool comDeSq(int a, int b)
{
	long long p1, p2;
	p1 = abs(squere[a][2] - squere[a][0]);
	p1 *= abs(squere[a][3] - squere[a][1]);
	p2 = abs(squere[b][2] - squere[b][0]);
	p2 *= abs(squere[b][3] - squere[b][1]);
	return p1 > p2;
}

void build(int v, int l, int r)
{
	if (l == r)
	{
		T[v] = {ySort[l]};
		return;
	}

	int m = (l + r) / 2;
	build(v * 2, l, m);
	build(v * 2 + 1, m + 1, r);
	T[v].resize(r - l + 1);
	for (int i = l; i <= r; ++i)
		T[v][i - l] = ySort[i];
	sort(T[v].begin(), T[v].end(), comX);
}

void del(int v, int l, int r, int ymin, int ymax, int xmin, int xmax)
{
	if ((ymax <= point[ySort[l]][1]) || (point[ySort[r]][1] <= ymin)) return;
	if (!((ymin < point[ySort[l]][1]) && (point[ySort[r]][1] < ymax)))
	{
		int m = (l + r) / 2;
		del(v * 2, l, m, ymin, ymax, xmin, xmax);
		del(v * 2 + 1, m + 1, r, ymin, ymax, xmin, xmax);
		return;
	}

	int it1, it2, ll, rr;
	ll = -1;
	rr = T[v].size();
	while (ll + 1 < rr)
	{
		int m = (ll + rr) / 2;
		if (point[T[v][m]][0] > xmin)
			rr = m;
		else
			ll = m;
	}
	it1 = rr;
	ll = -1;
	rr = T[v].size();
	while (ll + 1 < rr)
	{
		int m = (ll + rr) / 2;
		if (point[T[v][m]][0] < xmax)
			ll = m;
		else
			rr = m;
	}
	it2 = ll;
	for (int i = it1; i <= it2; ++i)
		used[T[v][i]] = true;
}

int main()
{
	cin >> n;
	squere.resize(n, vector<int>(4));
	point.resize(n, vector<int>(2));
	for (int i = 0; i < n; ++i)
	{
		for (auto&j: squere[i])
		{
			cin >> j;
			j *= 2;
		}
		point[i] = { squere[i][0] + 1, squere[i][1] + 1 };
	}
	ySort.resize(n);
	sqSort.resize(n);
	for (int i = 0; i < n; ++i)
	{
		ySort[i] = i;
		sqSort[i] = i;
	}
	sort(ySort.begin(), ySort.end(), comY);
	sort(sqSort.begin(), sqSort.end(), comDeSq);

	T.resize(4 * n + 2);
	build(1, 0, n - 1);

	used.resize(n, false);
	for (int i = 0; i < n; ++i)
		if (!used[sqSort[i]])
		{
			del(1, 0, n - 1, squere[sqSort[i]][1], squere[sqSort[i]][3], squere[sqSort[i]][0], squere[sqSort[i]][2]);
			used[sqSort[i]] = false;
		}
	int count = 0;
	for (auto&i : used)
		if (!i) ++count;
	cout << count;

	return 0;
}