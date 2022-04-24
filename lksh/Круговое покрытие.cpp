#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

double eps = 0.000001;

struct point
{
	double x, y;
	point() : x(0), y(0) {};
	point(double x, double y) : x(x), y(y) {};
};

double dx(point a, point b)
{
	return abs(a.x - b.x);
}

double dy(point a, point b)
{
	return abs(a.y - b.y);
}

bool pinc(point p, point o, double r)
{
	if (r < 0) return false;
	return (dx(p, o) * dx(p, o) + dy(p, o) * dy(p, o)) <= r * r;
}

int n;
vector<point> a;
vector<double> R;
double r, xa, xb, ya, yb;

bool trimx()
{
	for (int i = 0; i < n; ++i)
	{
		double ny = ya;
		if (ya <= a[i].y && a[i].y <= yb) 
			ny = a[i].y;
		else
		{
			if (abs(a[i].y - yb) < abs(a[i].y - ya))
				ny = yb;
		}
		double dsq = (r - R[i]) * (r - R[i]) - (ny - a[i].y) * (ny - a[i].y);
			if (dsq < 0) return false;
		xa = max(xa, a[i].x - sqrt(dsq));
		xb = min(xb, a[i].x + sqrt(dsq));
		if (xa > xb) return false;
	}

	return true;
}

bool trimy()
{
	for (int i = 0; i < n; ++i)
	{
		double nx = xa;
		if (xa <= a[i].x && a[i].x <= xb)
			nx = a[i].x;
		else
		{
			if (abs(a[i].x - xb) < abs(a[i].x - xa))
				nx = xb;
		}
		double dsq = (r - R[i]) * (r - R[i]) - (nx - a[i].x) * (nx - a[i].x); 
		if (dsq < 0) return false;
		ya = max(ya, a[i].y - sqrt(dsq));
		yb = min(yb, a[i].y + sqrt(dsq));
		if (ya > yb) return false;
	}

	return true;
}

bool check()
{
	xa = ya = -3000; xb = yb = 3000;
	for (int i = 0; i < 10000; ++i)
	{
		if (!trimx()) return false;
		if (!trimy()) return false;
	}
	double x = (xa + xb) / 2, y = (ya + yb) / 2;
	point p = point(x, y);
	for (int i = 0; i < n; ++i)
		if (!pinc(p, a[i], r - R[i]))
			return false;

	return true;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n; a.resize(n); R.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i].x >> a[i].y >> R[i];
	double L = 0, R = 7000;
	while (L + eps < R)
	{
		r = (L + R) / 2;
		if (check())
			R = r;
		else
			L = r;
	}
	cout << fixed << setprecision(16) << R << '\n';

	return 0;
}