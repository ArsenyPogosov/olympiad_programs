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

long long GCD(long long a, long long b)
{
	return (b ? GCD(b, a % b) : a);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n; cin >> n;
	Vector mm; cin >> mm;
	vector<Vector> agrigat(n);
	for (auto& i : agrigat) cin >> i;

	set<pair<long long, long long>> res;
	for (long long i = 0; i < n; ++i)
	{
		long long left = -1;
		for (long long j = 0; j < n; ++j)
			if (j != i)
			{
				if (left == -1)
				{
					left = j;
					continue;
				}
				Vector a = (agrigat[j] - agrigat[i]), 
				       b = (agrigat[left] - agrigat[i]);
				if ((a ^ b) > 0)
				{
					left = j;
					continue;
				}
				if ((a ^ b) == 0 && a.sqsize() > b.sqsize())
					left = j;
			}
		bool bad = false;
		for (long long j = 0; j < n && !bad; ++j)
			if (j != i)
				if (((agrigat[j] - agrigat[i]) ^ (agrigat[left] - agrigat[i])) > 0)
					bad = true;
		if (bad) continue;
		long long check1 = ((mm - agrigat[i]) * (agrigat[left]-agrigat[i])),
		          check2 = ((mm - agrigat[left]) * (agrigat[i] - agrigat[left]));

		if (check1 > 0 && check2 > 0)
		{
			long long dx = (agrigat[i] - agrigat[left]).x,
				dy = (agrigat[i] - agrigat[left]).y,
				d = GCD(abs(dx), abs(dy));
			res.emplace(dx / d, dy / d);
		}
	}
	cout << res.size() << '\n';

	return 0;
}