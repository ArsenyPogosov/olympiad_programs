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

long long n;
vector<vector<vector<long long>>> F;

long long Sum(long long i, long long j, long long k)
{
	long long res = 0;
	long long i1 = i, j1 = j, k1 = k;
	while (i >= 0)
	{
		while (j >= 0)
		{
			while (k >= 0)
			{
				res += F[i][j][k];
				k = (k & (k + 1)) - 1;
			}
			k = k1;
			j = (j & (j + 1)) - 1;
		}
		j = j1;
		i = (i & (i + 1)) - 1;
	}
	return res;
}

long long Sum(long long i1, long long j1, long long k1,
	long long i2, long long j2, long long k2)
{
	return Sum(i2, j2, k2) - Sum(i1 - 1, j2, k2) - Sum(i2, j1 - 1, k2) - Sum(i2, j2, k1 - 1) + Sum(i1 - 1, j1 - 1, k2) + Sum(i2, j1 - 1, k1 - 1) + Sum(i1 - 1, j2, k1 - 1) - Sum(i1 - 1, j1 - 1, k1 - 1);
}

void change(long long i, long long j, long long k, long long add)
{
	long long i1 = i, j1 = j, k1 = k;
	while (i < n)
	{
		while (j < n)
		{
			while (k < n)
			{
				F[i][j][k] += add;
				k = k | (k + 1);
			}
			k = k1;
			j = j | (j + 1);
		}
		j = j1;
		i = i | (i + 1);
	}
}

int main()
{
	cin >> n;
	F.resize(n, vector<vector<long long>>(n, vector<long long>(n)));

	while (true)
	{
		long long m; cin >> m;
		if (m == 1)
		{
			long long x, y, z, k; cin >> x >> y >> z >> k;
			change(x, y, z, k);
		}
		if (m == 2)
		{
			long long x1, y1, z1, x2, y2, z2; cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
			cout << Sum(x1, y1, z1, x2, y2, z2) << '\n';
		}
		if (m == 3)
		{
			break;
		}
	}

	return 0;
}