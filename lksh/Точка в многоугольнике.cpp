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

double Angle(Vec v)
{
	return atan2(v.y, v.x);
}

double Angle(Vec v1, Vec v2)
{
	return Angle(Vec(v1*v2, v1^v2));
}

Vec NormVec(Line alpha)
{
	return Vec(alpha.a, alpha.b);
}

bool IsParalel(Line alpha, Line beta)
{
	return abs(alpha.a * beta.b - alpha.b * beta.a) < E;
}

double SqDist(Vec a, Vec b)
{
	double dx = a.x - b.x, dy = a.y - b.y;
	return dx * dx + dy * dy;
}

double Dist(Vec a, Vec b)
{
	return sqrt(SqDist(a, b));
}

double Dist(Line alpha, Vec a)
{
	return (alpha.a * a.x + alpha.b * a.y + alpha.c) / sqrt(alpha.a*alpha.a + alpha.b*alpha.b);
}

bool On(Line alpha, Vec a)
{
	return abs(Dist(alpha, a)) < E;
}

double Len(Vec v)
{
	return sqrt(v.x * v.x + v.y * v.y);
}

Vec Mirror(Line alpha, Vec a)
{
	return NormVec(alpha) * (-Dist(alpha, a) * 2 / Len(NormVec(alpha))) + a;
}

bool In(vector<Vec> figure, Vec v)
{
	int n = figure.size();
	for (int i = 0; i < n; ++i)
		if (On(Line(figure[(i + 1) % n], figure[i]), v))
		{
			Vec h = figure[(i + 1) % n] - figure[i];
			if (h*(v - figure[i]) > 0 && (-h)*(v - figure[(i + 1) % n]) > 0)
				return true;
		}

	double angle = 0;
	for (int i = 0; i < n; ++i)
		angle += Angle(figure[i] - v, figure[(i + 1) % n] - v);
	if (abs(angle) < 1)
		return false;
	
	return true;
}

int main()
{
	int n;
	cin >> n;
	Vec v;
	cin >> v;
	vector<Vec> figure(n);
	for (auto&i : figure)
		cin >> i;
	if (In(figure, v))
		cout << "YES";
	else
		cout << "NO";

	return 0;
}