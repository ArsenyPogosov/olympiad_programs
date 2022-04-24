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
	friend const Vec operator-(const Vec& a)
	{
		return Vec(-a.x, -a.y);
	}
	friend const Vec operator+(const Vec& a, const Vec& b)
	{
		return Vec(a.x + b.x, a.y + b.y);
	}
	friend const Vec operator-(const Vec& a, const Vec& b)
	{
		return a + (-b);
	}
	const double operator*(const Vec& b)
	{
		return this->x*b.x + this->y*b.y;
	}
	const double operator^(const Vec& b)
	{
		return this->x*b.y - this->y*b.x;
	}
	friend istream& operator >> (istream& c, Vec& v)
	{
		c >> v.x >> v.y;
		return c;
	}
};

double Angle(Vec v)
{;
	return atan2(v.y, v.x);
}

double Angle(Vec v1, Vec v2)
{
	return Angle(Vec(v1*v2, v1^v2));
}

struct Line
{
	double a, b, c;
	Line(double _a = 0, double _b = 0, double _c = 0)
	{
		a = _a;
		b = _b;
		c = _c;
	}
	Line(double x1, double y1, double x2, double y2)
	{
		a = y2 - y1;
		b = x1 - x2;
		c = -(y2 - y1) * x1 - (x1 - x2) * y1;
	}
	Line(Vec f, Vec s)
	{
		Line res = Line(f.x, f.y, s.x, s.y);
		a = res.a;
		b = res.b;
		c = res.c;
	}
};

bool IsParalel(Line alpha, Line beta)
{
	return abs(alpha.a * beta.b - alpha.b * beta.a) < E;
}

int main()
{
	// DAROVA
	Vec a, b, c, d, e, f;
	cin >> a >> b >> c >> d >> e >> f;
	vector<double> abc(3), def(3);
	abc[0] = abs(Angle(a - c, b - c));
	abc[1] = abs(Angle(b - a, c - a));
	abc[2] = abs(Angle(a - b, c - b));
	def[0] = abs(Angle(d - f, e - f));
	def[1] = abs(Angle(e - d, f - d));
	def[2] = abs(Angle(d - e, f - e));
	sort(abc.begin(), abc.end());
	sort(def.begin(), def.end());
	bool flag = true;
	for (int i = 0; i < 3; ++i)
		flag &= abs(abc[i] - def[i]) < E;
	if (flag)
		cout << "YES";
	else
		cout << "NO";

	return 0;
}