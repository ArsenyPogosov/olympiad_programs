//source: 
//status: coding

#include <bits/stdc++.h>
#include<unordered_map>
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

const double INF = 1e17;

struct point
{
	long long id, x, y;
	point() {}
	point(long long id, long long x, long long y) : id(id), x(x), y(y) {}
};

long long geti(long long x, long long y)
{
	return max(abs(x), abs(y));
}

double dist(long long a, long long b, long long c, long long d)
{
	return sqrt((c - a) * (c - a) + (d - b) * (d - b));
}

double iidist(long long a, long long b)
{
	double res = 0, i = geti(a, b);
	if (a == i)
		return res + abs(i - b);
	else
		res += i * 2;
	if (b == -i)
		return res + abs(i - a);
	else
		res += i * 2;
	if (a == -i)
		return res + abs(-i - b);
	else
		res += i * 2;
	return res + abs(-i - a);
}

double iidist(point x)
{
	return iidist(x.x, x.y);
}

int main()
{
	long long n, k; cin >> n >> k;
	unordered_map<long long, vector<point>> cr;
	vector<vector<pair<long long, double>>> Graph(n * 2 + 2);
	for (long long i = 0; i < n; ++i)
	{
		long long a, b, c, d; cin >> a >> b >> c >> d;
		cr[geti(a, b)].push_back(point(i * 2, a, b));
		cr[geti(c, d)].push_back(point(i * 2 + 1, c, d));
		double dd = dist(a, b, c, d);
		Graph[i * 2].push_back({ i * 2 + 1, dd });
		Graph[i * 2 + 1].push_back({ i * 2, dd });
	}
	long long a, b, c, d; cin >> a >> b >> c >> d;
	cr[geti(a, b)].push_back(point(n * 2, a, b));
	cr[geti(c, d)].push_back(point(n * 2 + 1, c, d));
	for (auto& i : cr)
	{
		vector<point> &tek = i.second;
		sort(tek.begin(), tek.end(), [&](point a, point b) {
			return iidist(a.x, a.y) < iidist(b.x, b.y);
		});
		for (long long j = 0; j < tek.size(); ++j)
		{
			double d1 = abs(iidist(tek[(j + 1) % tek.size()]) - iidist(tek[j]));
			double d = min(d1, i.first * 8 - d1);
			Graph[tek[j].id].push_back({ tek[(j + 1) % tek.size()].id, d });
			Graph[tek[(j + 1) % tek.size()].id].push_back({ tek[j].id, d });
		}
	}
	vector<double> dist(n * 2 + 2, INF); dist[n * 2] = 0;
	set<pair<double, long long>> s; s.insert({ 0, n * 2 });
	while (s.size())
	{
		long long v = s.begin()->second; s.erase(s.begin());
		if (dist[v] == INF) break;
		for (auto&i: Graph[v])
			if (dist[i.first] > dist[v] + i.second)
			{
				s.erase({ dist[i.first], i.first});
				dist[i.first] = dist[v] + i.second;
				s.insert({ dist[i.first], i.first });
			}
	}
	if (dist[n * 2 + 1] != INF)
		cout << fixed << setprecision(16) << dist[n * 2 + 1];
	else
		cout << -1;

	return 0;
}