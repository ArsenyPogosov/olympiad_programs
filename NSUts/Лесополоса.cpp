#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

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

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	Vector m1, m2, l1, l2, r1, r2; cin >> m1 >> m2 >> l1 >> l2 >> r1 >> r2;
	int n; cin >> n;
	int resl = 0, resr = 0;
	while (n--)
	{
		Vector p; cin >> p;
		if (((l2 - l1) ^ (p - l1)) > 0) continue;
		if (((r2 - r1) ^ (p - r1)) < 0) continue;
		if (((m2 - m1) ^ (p - m1)) > 0)
			++resl;
		else
			++resr;
	}
	cout << resl << ' ' << resr << '\n';

	return 0;
}