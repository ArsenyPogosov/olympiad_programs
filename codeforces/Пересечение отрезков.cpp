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
	Vector operator*(const long long k) const { return Vector(x * k, y * k); }
	T operator*(const Vector& b) const { return x * b.x + y * b.y; }
	T operator^(const Vector& b) const { return x * b.y - y * b.x; }

	void operator+=(const Vector& b) { x += b.x; y += b.y; }
	void operator-=(const Vector& b) { x -= b.x; y -= b.y; }
	void operator*=(const T k) { x *= k; y *= k; }

	bool operator<(const Vector& b) const { return (*this ^ b) > 0; }
	bool operator<=(const Vector& b) const { return (*this ^ b) >= 0; }
	bool operator>(const Vector& b) const { return (*this ^ b) < 0; }
	bool operator>=(const Vector& b) const { return (*this ^ b) <= 0; }
	bool operator==(const Vector& b) const { return x == b.x && y == b.y; }

	double len() { return sqrt(x * x + y * y); }
	double angle() { return atan2(y, x); }

	friend istream& operator>>(istream& s, Vector& v) { return s >> v.x >> v.y; }
	friend ostream& operator<<(ostream& s, const Vector& v) { return s << v.x << ' ' << v.y; }
};

template <typename T>
double len(Vector<T> v) { return sqrt(v.x * v.x + v.y * v.y); }
template <typename T>
double angle(Vector<T> v) { return atan2(v.y, v.x); }
template <typename T>
double angle(Vector<T> v1, Vector<T> v2) { return atan2(v1 ^ v2, v1 * v2); }

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

int main()
{
	Vector<long long> a, b, c, d; cin >> a >> b >> c >> d;
	cout << (segcrseg(a, b, c, d) ? "YES" : "NO") << '\n';

	return 0;
}