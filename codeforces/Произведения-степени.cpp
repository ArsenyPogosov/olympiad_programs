//source: 
//status: coding

#include <bits/stdc++.h>
#include <map>
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

long long k;

long long nn(long long n)
{
	long long res = 1;
	for (long long i = 2; i * i < n; ++i)
	{
		long long count = 0;
		while (n % i == 0)
		{
			++count; n /= i;
		}
		count %= k;
		for (long long j = 0; j < count; ++j)
			res *= i;
	}
	return res;
}

long long nm(long long n)
{
	long long res = 1;
	for (long long i = 2; i * i < n; ++i)
	{
		long long count = 0;
		while (n % i == 0)
		{
			++count; n /= i;
		}
		count %= k;
		for (long long j = 0; j < k - count; ++j)
			res *= i;
	}
	return res;
}

int main()
{
	long long n, k;
	cin >> n >> k;
	map<long long, long long> mapp;
	for (long long i = 0; i < n; ++i)
	{
		long long h;
		cin >> h;
		++mapp[nn(h)];
	}
	long long res = 0;
	for (auto& i : mapp)
	{
	}
		long long h = nm(i.first);
		if (mapp.find(h) != mapp.end())
			res == i.second * mapp[h];
	cout << res / 2;

	return 0;
}