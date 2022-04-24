#include <iostream>
#include <iomanip>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
#include <cmath>
//#include <string>
using namespace std;

const double INF = 1000000000000000;
const double E = 0.00000001;
const double pi = 3.1415926535897932384626433832795;

struct Vec
{
	double x, y;
	Vec(double _x = 0, double _y = 0)
	{
		x = _x;
		y = _y;
	}
	friend Vec operator-(const Vec& a)
	{
		return Vec(-a.x, -a.y);
	}
	friend Vec operator+(const Vec& a, const Vec& b)
	{
		return Vec(a.x + b.x, a.y + b.y);
	}
	friend Vec operator-(const Vec& a, const Vec& b)
	{
		return a + (-b);
	}
	double operator*(const Vec& b)
	{
		return this->x*b.x + this->y*b.y;
	}
	Vec operator*(const double& k)
	{
		return Vec(this->x*k, this->y*k);
	}
	double operator^(const Vec& b)
	{
		return this->x*b.y - this->y*b.x;
	}
	friend istream& operator >> (istream& c, Vec& v)
	{
		c >> v.x >> v.y;
		return c;
	}
};

bool eq(Vec a, Vec b)
{
	return abs(a.x - b.x) < E && abs(a.y - b.y) < E;
}

double Angle(Vec v)
{
	return atan2(v.y, v.x);
}

double Angle(Vec v1, Vec v2)
{
	return Angle(Vec(v1*v2, v1^v2));
}

bool In(vector<Vec> figure, Vec v)
{
	int n = figure.size();
	double angle = 0;
	for (int i = 0; i < n; ++i)
		angle += Angle(figure[i] - v, figure[(i + 1) % n] - v);
	if (abs(angle) < 1)
		return false;

	return true;
}

bool cross(Vec a1, Vec b1, Vec a2, Vec b2)
{
	if (((b1 - a1) ^ (a2 - a1)) * ((b1 - a1) ^ (b2 - a1)) > 0)
		return false;
	if (((b2 - a2) ^ (a1 - a2)) * ((b2 - a2) ^ (b1 - a2)) > 0)
		return false;
	return true;
}

bool RoadEnds(vector<Vec> polygon, Vec a, Vec b)
{
	int n = polygon.size();
	for (int i = 0; i < n; ++i)
	{
		if (eq(a, polygon[i]) || eq(b, polygon[i]) || eq(a, polygon[(i + 1) % n]) || eq(b, polygon[(i + 1) % n]))
			continue;
		if (cross(a, b, polygon[i], polygon[(i + 1) % n]))
			return false;
	}
	Vec x = (a + b) * 0.5;
	return In(polygon, x);
}

double d(Vec a, Vec b)
{
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}

int main()
{
	int n;
	cin >> n;
	vector<Vec> polygon(n);
	for (auto& i : polygon)
		cin >> i;
	vector<vector<double>> e;
	e.reserve(n * n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if ((i != j) && RoadEnds(polygon, polygon[i], polygon[j]))
			{
				e.push_back({ double(i), double(j), d(polygon[i], polygon[j]) });
				e.push_back({ double(j), double(i), d(polygon[i], polygon[j]) });
			}
	for (int i = 0; i < n; ++i)
	{
		int j = (i + 1) % n;
		e.push_back({ double(i), double(j), d(polygon[i], polygon[j]) });
		e.push_back({ double(j), double(i), d(polygon[i], polygon[j]) });
	}
	int k, l;
	cin >> k >> l;
	--k;
	--l;
	vector<double> dist(n, INF);
	dist[k] = 0;
	for (long long i = 0; i < n; ++i)
	{
		bool br = true;
		for (auto&j : e)
			if ((dist[j[1]] > dist[j[0]] + j[2]) && (dist[j[0]] != INF))
			{
				dist[j[1]] = dist[j[0]] + j[2];
				br = false;
			}
		if (br)
			break;
	}
	cout << setprecision(20) << dist[l];

	return 0;
}