//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/258672/problems
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

vector<long long> mass, F;

long long Sum(long long r)
{
	long long res = 0;
	while (r >= 0)
	{
		res += F[r];
		r = (r & (r + 1)) - 1;
	}
	return res;
}

long long Sum(long long l, long long r)
{
	return Sum(r) - (l > 0 ? Sum(l - 1) : 0);
}

void change(long long i, long long x)
{
	long long add = x - mass[i];
	mass[i] = x;
	while (i < F.size())
	{
		F[i] += add;
		i = i | (i + 1);
	}
}

void build()
{
	F.resize(mass.size());
	for (long long i = 0; i < mass.size(); ++i) change(i, mass[i]);
}

int main()
{
	long long n, m; cin >> n >> m;
	mass.resize(n);
	build();
	for (long long i = 0; i < m; ++i)
	{
		char a;
		long long b, c;
		cin >> a >> b >> c;
		if (a == 'A') change(b - 1, c);
		if (a == 'Q') cout << Sum(b - 1, c - 1) << '\n';
	}

	return 0;
}