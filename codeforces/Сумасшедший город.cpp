#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct Vector
{
	long long x, y;

	Vector() : x(0), y(0) {};
	Vector(long long x, long long y) : x(x), y(y) {};
	Vector(const Vector& X) { *this = X; };

	friend istream& operator>>(istream& in, Vector& v)
	{
		return in >> v.x >> v.y;
	}
	friend ostream& operator<<(ostream& out, const Vector& v)
	{
		return out << v.x << ' ' << v.y;
	}

	Vector operator+() const
	{
		return *this;
	}
	Vector operator+(const Vector& b) const
	{
		return Vector(x + b.x, y + b.y);
	}
	void operator+=(const Vector& b)
	{
		x += b.x;
		y += b.y;
	}

	Vector operator-() const
	{
		return Vector(-x, -y);
	}
	Vector operator-(const Vector& b) const
	{
		return Vector(x - b.x, y - b.y);
	}
	void operator-=(const Vector& b)
	{
		x -= b.x;
		y -= b.y;
	}

	Vector operator*(const long long k) const
	{
		return Vector(x * k, y * k);
	}
	void operator*=(const long long k)
	{
		x *= k;
		y *= k;
	}

	Vector operator/(const long long k) const
	{
		return Vector(x / k, y / k);
	}
	void operator/=(const long long k)
	{
		x /= k;
		y /= k;
	}

	long long operator*(const Vector& b) const
	{
		return x * b.x + y * b.y;
	}
	long long operator^(const Vector& b) const
	{
		return x * b.y - y * b.x;
	}

	long long sqlen() const
	{
		return (*this) * (*this);
	}
	friend long long sqlen(const Vector& v)
	{
		return (v) * (v);
	}
	double len() const
	{
		return sqrt((*this) * (*this));
	}
	friend double len(const Vector& v)
	{
		return sqrt((v) * (v));
	}

	bool operator==(const Vector& b) const
	{
		return (x == b.x) && (y == b.y);
	}
};

struct Line
{
	long long a, b, c;

	Line() : a(0), b(1), c(0) {};
	Line(long long a, long long b, long long c) : a(a), b(b), c(c) {};
	Line(const Line& l) { *this = l; };

	friend istream& operator>>(istream& in, Line& l)
	{
		return in >> l.a >> l.b >> l.c;
	}
	friend ostream& operator<<(ostream& out, const Line& l)
	{
		return out << l.a << ' ' << l.b << ' ' << l.c;
	}

	Vector normal() const
	{
		return { a, b };
	}
	friend Vector normal(const Line& l)
	{
		return { l.a, l.b };
	}

	Vector direct() const
	{
		return { b, -a };
	}
	friend Vector direct(const Line& l)
	{
		return { l.b, -l.a };
	}

	long long result(const Vector& v) const
	{
		return a * v.x + b * v.y + c;
	}
	friend long long result(const Line& l, const Vector& v)
	{
		return l.a * v.x + l.b * v.y + l.c;
	}

	bool contain(const Vector& v) const
	{
		return !this->result(v);
	}
	friend long long contain(const Line& l, const Vector& v)
	{
		return !l.result(v);
	}

	double dist(const Vector& v) const
	{
		return this->result(v)/len(this->normal());
	}
	double dist(const Line& l, const Vector& v)
	{
		return l.result(v) / len(l.normal());
	}
};

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	Vector a, b; cin >> a >> b;
	int n; cin >> n;
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		Line l; cin >> l;
		if (l.dist(a) * l.dist(b) < 0)
			++count;
	}
	cout << count << '\n';

	return 0;
}