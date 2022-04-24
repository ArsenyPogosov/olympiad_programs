//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/259770/problem/A
//status: coding

#include <bits/stdc++.h>
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

const double PI = atan2(0, -1);
const double eps = 0.0000001;

bool eq(double a, double b)
{
	return abs(a - b) < 2 * eps;
}

bool sm(double a, double b)
{
	return (a < b) && (!eq(a, b));
}

bool gr(double a, double b)
{
	return (a > b) && (!eq(a, b));
}

template <typename T>
struct Vector
{
	T x, y;
	Vector() { x = 0; y = 0; }
	Vector(T _x, T _y) { x = _x; y = _y; }
	Vector(T x1, T y1, T x2, T y2) { x = x2 - x1; y = y2 - y1; }
	Vector(Vector a, Vector b) { x = a.x - b.x; y = a.y - b.y; }

	Vector operator+(const Vector& b) const { return Vector(x + b.x, y + b.y); }
	Vector operator-(const Vector& b) const { return Vector(x - b.x, y - b.y); }
	Vector operator+() const { return Vector(+x, +y); }
	Vector operator-() const { return Vector(-x, -y); }
	Vector operator*(const T k) const { return Vector(x * k, y * k); }
	Vector operator/(const T k) const { return Vector(x / k, y / k); }
	T operator*(const Vector& b) const { return x * b.x + y * b.y; }
	T operator^(const Vector& b) const { return x * b.y - y * b.x; }

	void operator+=(const Vector& b) { x += b.x; y += b.y; }
	void operator-=(const Vector& b) { x -= b.x; y -= b.y; }
	void operator*=(const T k) { x *= k; y *= k; }
	void operator/=(const T k) { x /= k; y /= k; }

	bool operator<(const Vector& b) const { return (*this ^ b) > 0; }
	bool operator<=(const Vector& b) const { return (*this ^ b) >= 0; }
	bool operator>(const Vector& b) const { return (*this ^ b) < 0; }
	bool operator>=(const Vector& b) const { return (*this ^ b) <= 0; }
	bool operator==(const Vector& b) const { return x == b.x && y == b.y; }

	double len() { return sqrt(x * x + y * y); }
	T sqlen() { return x * x + y * y; }
	double angle() { return atan2(y, x); }

	void normalize() { T le = T(len());	x = x / le;	y = y / le; }
	void resize(double l) { T le = T(len()); x = x / le * l; y = y / le * l; }
	Vector norm() { return Vector(-y, x); }

	void rotate(double ang)
	{
		T x1 = x;
		x = x * cos(ang) - y * sin(ang);
		y = x1 * sin(ang) + y * cos(ang);
	}

	friend istream& operator>>(istream& s, Vector& v) { return s >> v.x >> v.y; }
	friend ostream& operator<<(ostream& s, const Vector& v) { return s << v.x << ' ' << v.y; }
};

template <typename T>
double len(Vector<T> v) { return sqrt(v.x * v.x + v.y * v.y); }
template <typename T>
double angle(Vector<T> v) { return atan2(v.y, v.x); }
template <typename T>
double angle(Vector<T> v1, Vector<T> v2) { return atan2(v1 ^ v2, v1 * v2); }

Vector<double> normalize(Vector<double> v) { v.normalize(); return v; }
Vector<double> resize(Vector<double> v, double l) { v.resize(l); return v; }
template <typename T>
Vector<T> norm(Vector<T> v) { return v.norm(); }

template <typename T>
struct Line
{
	T A, B, C;
	Line() { A = B = C = 0; }
	Line(const Vector<T>& a, const Vector<T>& b)
	{
		A = b.y - a.y;
		B = a.x - b.x;
		C = -(A * a.x + B * a.y);
	}
	Line(T _A, T _B, T _C) { A = _A; B = _B; C = _C; }

	Vector<T> norm() { return Vector<T>(A, B); }
	Vector<T> dir() { return norm().norm(); }

	bool contain(Vector<T> v)
	{
		return (A * v.x + B * v.y + C == 0);
	}
	double dist(Vector<T> v)
	{
		return (A * v.x + B * v.y + C) / norm().len();
	}
	T sqdist(Vector<T> v)
	{
		return (A * v.x + B * v.y + C) * (A * v.x + B * v.y + C) / norm().sqlen();
	}
	T sqdistn(Vector<T> v)
	{
		return (A * v.x + B * v.y + C) * (A * v.x + B * v.y + C);
	}
	Vector<T> h(Vector<T> v)
	{
		return v - resize(norm(), dist(v));
	}
	Vector<T> mir(Vector<T> v)
	{
		return v - resize(norm(), dist(v) * 2);
	}

	Line move(T dist)
	{
		Line res = *this; res.C -= dist * res.norm().len();
		return res;
	}

	friend istream& operator>>(istream& s, Line& v) { Vector<T> a, b; s >> a >> b; v = Line(a, b); return s; }
	friend ostream& operator<<(ostream& s, const Line& v) { return s << v.A << ' ' << v.B << ' ' << v.C; }
};

Vector<double> intersect(Line<double> l, Line<double> r)
{
	if (l.B == 0) swap(l, r);
	double x = (-r.C + l.C * r.B / l.B) / (r.A - l.A * r.B / l.B);
	double y = (-l.C - l.A * x) / l.B;
	return Vector<double>(x, y);
}

bool pinray(Vector<long long> p, Vector<long long> a, Vector<long long> b)
{
	if ((b - a) * (p - a) < 0) return false;
	return (((b - a) ^ (p - a)) == 0);
}

bool pinseg(Vector<long long> p, Vector<long long> a, Vector<long long> b)
{
	return pinray(p, a, b) && pinray(p, b, a);
}

bool segcrseg(Vector<long long> a, Vector<long long> b, Vector<long long> c, Vector<long long> d)
{
	if (pinseg(a, c, d)) return true;
	if (pinseg(b, c, d)) return true;
	if (pinseg(c, a, b)) return true;
	if (pinseg(d, a, b)) return true;
	if (((b - a) < (c - a)) == ((b - a) < (d - a))) return false;
	if (((d - c) < (a - c)) == ((d - c) < (b - c))) return false;
	return true;
}

template <typename T>
struct Polygon
{
	long long n;
	vector<Vector<T>> points;

	Polygon() { n = 0; }
	Polygon(long long _n) { n = _n;  points.resize(n); }
	Polygon(Vector<T>& _points) { points = _points;  n = points.size(); }

	bool contain(Vector<T> p)
	{
		double count = 0;
		for (long long i = 0; i < n; ++i)
		{
			if (pinseg(p, points[i], points[(i + 1) % n])) return true;
			count += angle(points[i] - p, points[(i + 1) % n] - p);
		}
		return fabs(count) > PI / 2;
	}

	double area()
	{
		double count = 0;
		for (int i = 1; i < n - 1; ++i)
			count += ((points[i] - points[0]) ^ (points[i + 1] - points[0]));
		return abs(count / 2);
	}

	bool convcheck()
	{
		vector<Vector<T>> npoints; npoints.reserve(n);
		npoints.push_back(points[0]);
		npoints.push_back(points[1]);
		for (int i = 2; i < n; ++i)
		{
			if (Line<long long>(npoints[npoints.size() - 2], npoints[npoints.size() - 1]).contain(points[i]))
				npoints.pop_back();
			npoints.push_back(points[i]);
		}
		int nn = npoints.size();
		double tek = 0, reg = angle(npoints[1] - npoints[0], npoints[2] - npoints[0]);
		reg /= abs(reg);
		for (int i = 2; i < nn; ++i)
		{
			if (angle(npoints[1] - npoints[0], npoints[i] - npoints[0]) * reg < tek * reg)
				return false;
			else
				tek = angle(npoints[1] - npoints[0], npoints[i] - npoints[0]);
		}
		double h = 0;
		for (int i = 0; i < nn; ++i)
			if (((npoints[i] - npoints[(i - 1 + nn) % nn]) ^ (npoints[(i + 1) % nn] - npoints[i])) * h < 0)
				return false;
			else
				h = ((npoints[i] - npoints[(i - 1 + nn) % nn]) ^ (npoints[(i + 1) % nn] - npoints[i]));
		return true;
	}

	friend istream& operator>>(istream& s, Polygon& v)
	{
		for (auto& i : v.points) s >> i;
		return s;
	}
	friend ostream& operator<<(ostream& s, const Polygon& v)
	{
		for (auto& i : v.points) s << i;
		return s;
	}
};

template <typename T>
bool contain(Polygon<T> Pol, Vector<T> p)
{
	double count = 0;
	for (long long i = 0; i < Pol.n; ++i)
	{
		if (pinseg(p, Pol.points[i], Pol.points[(i + 1) % Pol.n])) return true;
		count += angle(Pol.points[i] - p, Pol.points[(i + 1) % Pol.n] - p);
	}
	return fabs(count) > PI / 2;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cout << fixed << setprecision(32);
	Vector<long long> o; cin >> o; long long r; cin >> r; double rr = r;
	Vector<double> oo(double(o.x), double(o.y));
	long long a, b, c; cin >> a >> b >> c;
	Line<long long> l(a, b, c);
	Line<double> ll(double(l.A), double(l.B), double(l.C));
	if (l.sqdistn(o) > r * r * l.norm().sqlen())
		cout << 0;
	if (l.sqdistn(o) == r * r * l.norm().sqlen())
	{	
		cout << 1 << ' ' << ll.h(oo);
	}
	if (l.sqdistn(o) < r * r * l.norm().sqlen())
	{
		double dist = ll.dist(oo), nd = sqrt(rr * rr - dist * dist);
		cout << 2 << ' ' << ll.h(oo) + resize(ll.dir(), nd) << ' ' << ll.h(oo) - resize(ll.dir(), nd);
	}

	return 0;
}