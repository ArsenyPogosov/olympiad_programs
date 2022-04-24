#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long p = 1e9 + 7;
const long long div2 = (p + 1) / 2;
const long long div3 = ((p * 4 + 1) / 3) % p;

long long n3(long long n)
{
	return n * n % p * (n + 1) % p * (n + 1) % p * div2 % p * div2 % p;
}

long long n2(long long n)
{
	return n * (n + 1) % p * (n * 2 + 1) % p * div2 % p * div3 % p;
}

long long n1(long long n)
{
	return n * (n + 1) % p * div2 % p;
}

long long n0(long long n)
{
	return n;
}

long long rusq(long long l)
{
	return (8 * n3(l) % p + 16 * n2(l) % p + 12 * n1(l) % p + 3 * n0(l) % p + 3) % p;
}

long long rux(long long x, long long y)
{
	return (((4 * n2(x) % p + 5 * n1(x) % p + 3 * n0(x) % p) - (4 * n2(y) % p + 5 * n1(y) % p + 3 * n0(y) % p)) % p * (y + 1) % p + y * (y + 1) % p * div2 % p * (x - y) % p + p) % p;
}

long long ruy(long long x, long long y)
{
	return (((4 * n2(y) % p + 7 * n1(y) % p + 3 * n0(y) % p) - (4 * n2(x) % p + 7 * n1(x) % p + 3 * n0(x) % p)) % p * (x + 1) % p - x * (x + 1) % p * div2 % p * (y - x) % p + p) % p;
}

long long ru(long long x, long long y)
{
	if (x >= y)
		return (rusq(y) + rux(x, y)) % p;
	if (x < y)
		return (rusq(x) + ruy(x, y)) % p;
}

long long lusq(long long l)
{
	return (8 * n3(l) % p + 20 * n2(l) % p + 18 * n1(l) % p + 5 * n0(l) % p + 5) % p;
}

long long lux(long long x, long long y)
{
	return (((4 * n2(x) % p + 9 * n1(x) % p + 5 * n0(x) % p) - (4 * n2(y) % p + 9 * n1(y) % p + 5 * n0(y) % p)) % p * (y + 1) % p - y * (y + 1) % p * div2 % p * (x - y) % p + p) % p;
}

long long luy(long long x, long long y)
{
	return (((4 * n2(y) % p + 7 * n1(y) % p + 5 * n0(y) % p) - (4 * n2(x) % p + 7 * n1(x) % p + 5 * n0(x) % p)) % p * (x + 1) % p + x * (x + 1) % p * div2 % p * (y - x) % p + p) % p;
}

long long lu(long long x, long long y)
{
	if (x >= y)
		return (lusq(y) + lux(x, y)) % p;
	if (x < y)
		return (lusq(x) + luy(x, y)) % p;
}

long long ldsq(long long l)
{
	return (8 * n3(l) % p + 24 * n2(l) % p + 22 * n1(l) % p + 7 * n0(l) % p + 7) % p;
}

long long ldx(long long x, long long y)
{
	return (((4 * n2(x) % p + 9 * n1(x) % p + 7 * n0(x) % p) - (4 * n2(y) % p + 9 * n1(y) % p + 7 * n0(y) % p)) % p * (y + 1) % p + y * (y + 1) % p * div2 % p * (x - y) % p + p) % p;
}

long long ldy(long long x, long long y)
{
	return (((4 * n2(y) % p + 11 * n1(y) % p + 7 * n0(y) % p) - (4 * n2(x) % p + 11 * n1(x) % p + 7 * n0(x) % p)) % p * (x + 1) % p - x * (x + 1) % p * div2 % p * (y - x) % p + p) % p;
}

long long ld(long long x, long long y)
{
	if (x >= y)
		return (ldsq(y) + ldx(x, y)) % p;
	if (x < y)
		return (ldsq(x) + ldy(x, y)) % p;
}

long long rdsq(long long l)
{
	return (8 * n3(l) % p + 28 * n2(l) % p + 26 * n1(l) % p + 9 * n0(l) % p + 9) % p;
}

long long rdx(long long x, long long y)
{
	return (((4 * n2(x) % p + 5 * n1(x) % p + 9 * n0(x) % p) - (4 * n2(y) % p + 5 * n1(y) % p + 9 * n0(y) % p)) % p * (y + 1) % p - y * (y + 1) % p * div2 % p * (x - y) % p + p) % p;
}

long long rdy(long long x, long long y)
{
	return (((4 * n2(y) % p + 11 * n1(y) % p + 9 * n0(y) % p) - (4 * n2(x) % p + 11 * n1(x) % p + 9 * n0(x) % p)) % p * (x + 1) % p + x * (x + 1) % p * div2 % p * (y - x) % p + p) % p;
}

long long rd(long long x, long long y)
{
	if (x >= y)
		return (ldsq(y) + ldx(x, y)) % p;
	if (x < y)
		return (ldsq(x) + ldy(x, y)) % p;
}

long long u(long long y)
{
	return (4 * n2(y) % p + 7 * n1(y) % p + 4 * n0(y) % p) % p;
}

long long l(long long x)
{
	return (4 * n2(x) % p + 9 * n1(x) % p + 6 * n0(x) % p) % p;
}

long long d(long long y)
{
	return (4 * n2(y) % p + 11 * n1(y) % p + 8 * n0(y) % p) % p;
}

long long r(long long x)
{
	return (4 * n2(x) % p + 13 * n1(x) % p + 2 * n0(x) % p) % p;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long MXN = 0000;
	long long n; cin >> n; n = n * 2 + 1;
	if (n <= MXN * 2 + 2)
	{
		vector<vector<long long>> res(n, vector<long long>(n, 1e9));
		long long x = n / 2, y = n / 2;
		long long t = 1;
		for (long long l = 1; l <= n * 2 + 1; l += 2)
		{
			for (long long j = 0; j < l; ++j, ++y, ++t)
				if (0 <= x && x < n && 0 <= y && y < n)
					res[x][y] = min(res[x][y], t);
			for (long long j = 0; j < l; ++j, --x, ++t)
				if (0 <= x && x < n && 0 <= y && y < n)
					res[x][y] = min(res[x][y], t);
			for (long long j = 0; j < l + 1; ++j, --y, ++t)
				if (0 <= x && x < n && 0 <= y && y < n)
					res[x][y] = min(res[x][y], t);
			for (long long j = 0; j < l + 1; ++j, ++x, ++t)
				if (0 <= x && x < n && 0 <= y && y < n)
					res[x][y] = min(res[x][y], t);
		}

		vector<vector<long long>> ps(n + 1, vector<long long>(n + 1));
		for (long long i = 0; i < n; ++i)
			for (long long j = 0; j < n; ++j)
				ps[i + 1][j + 1] = res[i][j] + ps[i][j + 1] + ps[i + 1][j] - ps[i][j];

		long long q; cin >> q;
		while (q--)
		{
			long long x1, y1, x2, y2; cin >> y2 >> x1 >> y1 >> x2;
			x1 = n / 2 - x1; x2 = n / 2 - x2; y1 += n / 2; y2 += n / 2;
			cout << (ps[x1 + 1][y1 + 1] - ps[x2][y1 + 1] - ps[x1 + 1][y2] + ps[x2][y2]) % (long long)(1e9 + 7) << '\n';
		}
	}
	else
	{
		long long q; cin >> q;
		while (q--)
		{
			long long x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
			long long res = 0;
			if (0 < x2 && 0 < y2)
				res += ru(x2 - 1, y2 - 1);
			if (x1 < 0 && 0 < y2)
				res += lu(-x1 - 1, y2 - 1);
			if (x1 < 0 && y1 < 0)
				res += ru(-x1 - 1, -y1 - 1);
			if (0 < x2 && y1 < 0)
				res += ru(x2 - 1, -y1 - 1);
			if (x1 <= 0 && x2 <= 0 && y2 > 0)
				res += u(y2 - 1);
			if (x1 <= 0 && x2 <= 0 && y1 < 0)
				res += d(-y1 - 1);
			if (y1 <= 0 && y2 <= 0 && x2 > 0)
				res += r(x2 - 1);
			if (y1 <= 0 && y2 <= 0 && x1 < 0)
				res += l(-x1 - 1);
			if (x1 <= 0 && 0 <= x2 && y1 <= 0 && y2 <= 0)
				res += 1;
			cout << res << '\n';
		}
	}

	return 0;
}