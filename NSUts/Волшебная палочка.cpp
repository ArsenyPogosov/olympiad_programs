#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const double INF = 1e18;
const double pi = 3.14159265359;
const double eps = 1/1e6;

struct Vector
{
	long long x, y;

	Vector(long long x = 0, long long y = 0) : x(x), y(y) {};

	friend istream& operator>>(istream& in, Vector& a)
	{
		return in >> a.x >> a.y;
	}

	long long sqsize()
	{
		return x * x + y * y;
	}

	Vector operator-()
	{
		return { -x, -y };
	}

	Vector operator+(Vector b)
	{
		return { x + b.x, y + b.y };
	}
	Vector operator-(Vector b)
	{
		return { x - b.x, y - b.y };
	}

	friend long long operator*(Vector a, Vector b)
	{
		return a.x * b.x + a.y * b.y;
	}
	friend long long operator^(Vector a, Vector b)
	{
		return a.x * b.y - a.y * b.x;
	}
};

double len(Vector v)
{
	return sqrt(v.x * v.x + v.y * v.y);
}

double downdist(Vector l, Vector r, Vector p)
{
	if (p.x < l.x) return INF;
	if (p.x > r.x) return INF;
	double res = l.y - p.y + (r.y - l.y) * (p.x - l.x) * 1.0 / (r.x - l.x);
	if (res + eps< 0) return INF;
	return res;
}

double angdist(Vector o, Vector v, Vector p, bool rev)
{
	v = v - o; p = p - o;
	if (v.x*v.x + v.y*v.y < p.x*p.x+p.y*p.y) return INF;
	double res = atan2((v ^ p), v * p);
	if (res + eps < 0) res += 2 * pi;
	if (rev) res = 2 * pi - res;
	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	Vector l, r; cin >> l >> r;
	if (l.x > r.x) swap(l, r);
	int n; cin >> n;
	vector<Vector> mag(n);
	for (auto& i : mag) cin >> i;
	int f = -1;
	double fres = INF;
	for (int i = 0; i < n; ++i)
	{
		double tekres = downdist(l, r, mag[i]);
		if (tekres < fres)
		{
			fres = tekres;
			f = i;
		}
	}
	int s = -1;
	double sres = INF;
	bool rev = false;
	if ((r.x + l.x) > mag[f].x * 2)
		rev = true;
	for (int i = 0; i < n; ++i)
	{
		if (i == f) continue;
		double tekres = min(angdist(mag[f], l, mag[i], rev), angdist(mag[f], r, mag[i], rev));
		if (tekres < sres)
		{
			sres = tekres;
			s = i;
		}
	}
	if ((r.x + l.x) == mag[f].x * 2 && abs(sres) > eps)
	{
		cout << "Will stay at " << f + 1 << '\n';
		return 0;
	}
	if (s == -1)
	{
		cout << "Will spin around " << f + 1<< '\n';
	}
	else
	{
		cout << f + 1 << ' ' << s + 1 << '\n';
	}

	return 0;
}