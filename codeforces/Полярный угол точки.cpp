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

	double len() { return sqrt(x * x + y * y); }
	double angle() { return atan2(y, x); }

	friend istream& operator>>(istream& s, Vector& v) { return s >> v.x >> v.y; }
	friend ostream& operator<<(ostream& s, const Vector& v) { return s << v.x << ' ' << v.y; }
};

int main()
{
	Vector x; cin >> x;
	double res = x.angle();
	if (res < 0) res += PI * 2;
	cout << setprecision(15) << res;

	return 0;
}