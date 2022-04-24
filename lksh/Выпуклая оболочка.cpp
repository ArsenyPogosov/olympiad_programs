#include <iostream>
#include <iomanip>
#include <vector>
//#include <set>
//#include <list>
#include <map>
#include <algorithm>
#include <cmath>
//#include <string>
using namespace std;

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
	Vec(double fi)
	{
		x = cos(fi);
		y = sin(fi);
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
	friend bool operator<(const Vec& a, const Vec& b)
	{
		return pair<double, double>{ a.y, a.x } < pair<double, double>{b.y, b.x};
	}
	friend istream& operator >> (istream& c, Vec& v)
	{
		c >> v.x >> v.y;
		return c;
	}
};

struct polygon {
	vector<Vec> points;
	polygon()
	{
		points = vector<Vec>();
	}
	friend istream& operator >> (istream& c, polygon& v)
	{
		int n;
		cin >> n;
		v.points.resize(n);
		for (auto&i : v.points)
			c >> i;
		return c;
	}
};

double Angle(Vec v)
{
	return atan2(v.y, v.x);
}

double Angle(Vec v1, Vec v2)
{
	return Angle(Vec(v1*v2, v1^v2));
}

double Len(Vec v)
{
	return sqrt(v.x * v.x + v.y * v.y);
}

polygon Convex(vector<Vec> points)
{
	polygon res;
	int rn = 0, n = points.size();
	res.points.reserve(n);
	int f = 0;
	for (int i = 0; i < n; ++i)
		if (pair<double, double>{ points[i].y, points[i].x } < pair<double, double>{points[f].y, points[f].x})
			f = i;
	res.points.push_back(points[f]);

	sort(points.begin(), points.end(), [&](Vec a, Vec b) {
		a = a - res.points[0];
		b = b - res.points[0];
		if ((a^b) > E)
			return true;
		if (abs(a^b) < E && Len(a) < Len(b))
			return true;
		return false;
	});
	res.points.push_back(points[1]);
	rn += 2;

	for (int i = 2; i < n; ++i)
	{
		Vec c = points[i];
		while (rn > 1)
		{
			Vec a = res.points[rn - 2], b = res.points[rn - 1];
			if (((b - a) ^ (c - b)) <= E)
			{
				--rn;
				res.points.pop_back();
			}
			else
				break;
		}
		++rn;
		res.points.push_back(c);
	}

	return res;
}

double P(polygon p)
{
	double res = 0;
	int n = p.points.size();
	for (int i = 0; i < n; ++i)
		res += Len(p.points[i] - p.points[(i + 1) % n]);
	return res;
}

double S(polygon p)
{
	double res = 0;
	int n = p.points.size();
	for (int i = 0; i < n; ++i)
		res += ((p.points[i]-p.points[0]) ^ (p.points[(i + 1) % n] - p.points[0]))/2;
	return abs(res);
}

int main()
{
	int n;
	cin >> n;
	vector<Vec> points(n);
	for (auto&i : points)
		cin >> i;
	polygon Conv = Convex(points);
	map<Vec, int> m;
	for (int i = 0; i < n; ++i)
		m[points[i]] = i;
	cout << Conv.points.size() << '\n';
	for (auto&i : Conv.points)
		cout << m[i] + 1 << ' ';
	cout << '\n' <<setprecision(20) << P(Conv) << '\n' << S(Conv);

	return 0;
}