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

const double E = 0.000001;
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
	const Vec operator*(const double& k)
	{
		return Vec(this->x*k, this->y*k);
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
{
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

double Len(Vec v)
{
	return sqrt(v.x * v.x + v.y * v.y);
}

Vec Mirror(Line alpha, Vec a)
{
	return NormVec(alpha) * (-Dist(alpha, a) * 2 / Len(NormVec(alpha))) + a;
}

int main()
{
	Vec M, H;
	cin >> M >> H;
	double k, b;
	cin >> k >> b;
	Line river(k, -1, b);
	if (Dist(river, M)*Dist(river, H) > 0)
		cout << setprecision(20) << Dist(M, Mirror(river, H));
	else
		cout << "No solution.";

	return 0;
}