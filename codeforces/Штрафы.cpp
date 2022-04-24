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

struct Vector
{
	double x, y;
	Vector() { x = 0; y = 0; }
	Vector(double _x, double _y) { x = _x; y = _y; }

	Vector operator+(const Vector& b) const { return Vector(x + b.x, y + b.y); }
	Vector operator-(const Vector& b) const { return Vector(x - b.x, y - b.y); }
	Vector operator+() const { return Vector(+x, +y); }
	Vector operator-() const { return Vector(-x, -y); }
	Vector operator*(const int k) const { return Vector(x * k, y * k); }
	double operator*(const Vector& b) const { return x * b.x + y * b.y; }
	double operator^(const Vector& b) const { return x * b.y - y * b.x; }

	void operator+=(const Vector& b) { x += b.x; y += b.y; }
	void operator-=(const Vector& b) { x -= b.x; y -= b.y; }
	void operator*=(const int k) { x *= k; y *= k; }

	double len() { return sqrt(x * x + y * y); }
	double angle() { return atan2(y, x); }

	friend istream& operator>>(istream& s, Vector& v) { return s >> v.x >> v.y; }
	friend ostream& operator<<(ostream& s, const Vector& v) { return s << v.x << ' ' << v.y; }
};

double len(Vector v) { return sqrt(v.x * v.x + v.y * v.y); }
double angle(Vector v) { return atan2(v.y, v.x); }
double angle(Vector v1, Vector v2) { return atan2(v1 ^ v2, v1 * v2); }

int main()
{
	int n; cin >> n;
	vector<Vector> v(n); for (auto& i : v) cin >> i;
	int count = 0;
	for (int i = 1; i < n - 1; ++i)
	{
		double a = angle(v[i] - v[i - 1], v[i + 1] - v[i]);
		if (a > 0 && a != PI) ++count;
	}
	cout << count << ' ';

	return 0;
}