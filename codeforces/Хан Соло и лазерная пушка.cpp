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

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	Vector gun; cin >> gun;
	vector<Vector> v(n);
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		cin >> v[i]; v[i] -= gun; ++count;
		for (int j = 0; j < i; ++j)
			if (!(v[i] ^ v[j]))
			{
				--count;
				break;
			}
	}
	cout << count << '\n';

	return 0;
}