#include<iostream>
#include<vector>
using namespace std;

vector<int> fenv, mass;

int f(int i)
{
	return i&(i + 1);
}

int sum(int l)
{
	int res = 0;
	while (l >= 0)
	{
		res += fenv[l];
		l = f(l) - 1;
	}
	return res;
}

int sum(int l, int r)
{
	int res = sum(r) - sum(l - 1);
	if (l % 2 == 1)
		res = -res;
	return res;
}

void change(int a, int nw)
{
	if (a % 2 == 1)
		nw = -nw;
	int add = nw - mass[a];
	mass[a] += add;
	for (int i = a; i < fenv.size(); i = i | (i + 1))
		fenv[i] += add;
}

int main()
{
	// MY COMPUTER BEGAN TO WORKS ABOUT 10 MINUTES AGO!
	int n;
	cin >> n;
	mass.resize(n);
	fenv.resize(n);
	for (int i = 0; i < n; ++i)
	{
		int h;
		cin >> h;
		change(i, h);
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int r, a, b;
		cin >> r >> a >> b;
		if (r == 0)
			change(a - 1, b);
		if (r == 1)
			cout << sum(a - 1, b - 1) << '\n';
	}

	return 0;
}
