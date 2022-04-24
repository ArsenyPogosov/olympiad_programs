#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ifstream cin("sausage.in");
	ofstream cout("sausage.out");

	long long n; cin >> n;
	vector<pair<long long, long long>> points;
	double bl = -1;
	set<pair<pair<long long, long long>, pair<long long, long long>>> bxy;
	for (long long i = 0; i < n; ++i)
	{
		long long x, y, l; cin >> x >> y >> l;

		long long tx, ty;
		tx = x; ty = y;
		for (auto& i : points)
		{
			double tl = sqrt((tx - i.first) * (tx - i.first) + (ty - i.second) * (ty - i.second));
			if (tl > bl)
			{
				bl = tl;
				bxy.clear();
			}
			if (tl == bl)
				bxy.emplace(i, pair<long long, long long>{ tx, ty });
		}
		points.emplace_back(tx, ty);
		tx = x; ty = y + l;
		for (auto& i : points)
		{
			double tl = sqrt((tx - i.first) * (tx - i.first) + (ty - i.second) * (ty - i.second));
			if (tl > bl)
			{
				bl = tl;
				bxy.clear();
			}
			if (tl == bl)
				bxy.emplace(i, pair<long long, long long>{ tx, ty });
		}
		points.emplace_back(tx, ty);
		tx = x + l; ty = y;
		for (auto& i : points)
		{
			double tl = sqrt((tx - i.first) * (tx - i.first) + (ty - i.second) * (ty - i.second));
			if (tl > bl)
			{
				bl = tl;
				bxy.clear();
			}
			if (tl == bl)
				bxy.emplace(i, pair<long long, long long>{ tx, ty });
		}
		points.emplace_back(tx, ty);
		tx = x + l; ty = y + l;
		for (auto& i : points)
		{
			double tl = sqrt((tx - i.first) * (tx - i.first) + (ty - i.second) * (ty - i.second));
			if (tl > bl)
			{
				bl = tl;
				bxy.clear();
			}
			if (tl == bl)
				bxy.emplace(i, pair<long long, long long>{ tx, ty });
		}
		points.emplace_back(tx, ty);
	}

	double bp = -1;
	for (auto& xy : bxy)
	{
		long long x1 = xy.first.first, y1 = xy.first.second;
		long long x2 = xy.second.first, y2 = xy.second.second;
		for (auto& i : points)
		{
			long long x3 = i.first, y3 = i.second;
			if (x1 == x3 && y1 == y3) continue;
			if (x2 == x3 && y2 == y3) continue;
			double tl13 = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
			double tl23 = sqrt((x2 - x3) * (x2 - x3) + (y2 - y3) * (y2 - y3));
			bp = max(bp, bl + tl13 + tl23);
		}
	}

	cout << fixed << setprecision(16) << bp << '\n' << fixed << setprecision(16) << bl << '\n';

	return 0;
}