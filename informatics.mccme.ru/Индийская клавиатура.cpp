#include <iostream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

int p, q;

bool contains(int x1, int y1, int x2, int y2)
{
	return ((x1 <= x2) &&
		(x1 + q - 1 >= x2) &&
		(y1 <= y2) &&
		(y1 + p - 1 >= y2));
}

int main()
{
	int n, m;
	cin >> n >> m >> p >> q;
	vector<pair<int, int>> Map(n*m + 1);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			int h; cin >> h;
			Map[h] = { i, j };
		}
	int s; cin >> s;
	int count{ 0 };
	int l, r, u, d;
	{
		int x; cin >> x;
		u = d = Map[x].first;
		l = r = Map[x].second;
	}
	for (int i = 2; i <= s; ++i) {
		int x; cin >> x; pair<int, int> coord = Map[x];
		if ((contains(l, u, coord.second, coord.first)) ||
			(contains(r - q + 1, u, coord.second, coord.first)) ||
			(contains(r - q + 1, d - p + 1, coord.second, coord.first)) ||
			(contains(l, d - p + 1, coord.second, coord.first)))
		{
			u = min(u, coord.first);
			d = max(d, coord.first);
			l = min(l, coord.second);
			r = max(r, coord.second);
			continue;
		}
		u = d = coord.first;
		l = r = coord.second;
		++count;
	}
	cout << count;

	return 0;
}