//source: http://neerc.ifmo.ru/school/io/archive/20191005/problems-20191005.pdf
//status: solved

#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
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

long long GCD(long long a, long long b)
{
	return b ? GCD(b, a % b) : a;
}

int main()
{
	long long n;
	cin >> n;
	vector<long long> mass(n);
	for (auto& i : mass) cin >> i;
	list<long long> toerase;
	long long it = 0, maxx = 1, gcd;
	while (it < n)
	{
		toerase.clear();
		toerase.push_back(it);
		gcd = mass[it];
		for (long long i = it + 1; i < n; ++i)
		{
			long long h = GCD(mass[i], gcd);
			if (h > 1)
			{
				toerase.push_back(i);
				gcd = h;
			}
		}
		maxx = max(maxx, long long(toerase.size()));
		for (auto& i : toerase)
			mass[i] /= gcd;
		while (it < n && mass[it] == 1)
			++it;
	}

	cout << maxx;

	return 0;
}