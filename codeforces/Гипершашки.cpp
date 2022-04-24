//source: 
//status: coding

#include <bits/stdc++.h>
using namespace std;
#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("game.in");
ofstream fout("game.out");
#define cin fin
#define cout fout
#endif
#pragma endregion

vector<long long> one, two, many;

long long countlr(long long l, long long r)
{
	return max(0ll, (long long)(upper_bound(one.begin(), one.end(), r) - lower_bound(one.begin(), one.end(), l)));
}

int main()
{
	long long n, k; cin >> n >> k;
	one.reserve(n); two.reserve(n); many.reserve(n);
	vector<long long> x(n);
	for (auto& i : x) cin >> i;
	sort(x.begin(), x.end());
	long long count = 0;
	for (long long i = 0; i < n; ++i)
	{
		if (i == 0 || x[i - 1] == x[i])
			++count;
		else
		{
			if (count >= 1)
				one.push_back(x[i - 1]);
			if (count >= 2)
				two.push_back(x[i - 1]);
			if (count >= 3)
				many.push_back(x[i - 1]);
			count = 1;
		}
	}
	if (count >= 1)
		one.push_back(x[n - 1]);
	if (count >= 2)
		two.push_back(x[n - 1]);
	if (count >= 3)
		many.push_back(x[n - 1]);
	long long res = 0;
	res += many.size();
	for (auto& i : two)
		res += (countlr((i + k - 1) / k, i * k) - 1)*3;
	for (auto& i : one)
	{
		long long t = countlr(i + 1, i * k);
		res += (t*(t-1)/2) * 6;
	}
	cout << res << '\n';

	return 0;
}