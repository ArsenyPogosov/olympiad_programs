//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/260745/problem/B 
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

int main()
{
	long long n, m; cin >> n >> m;
	set<pair<long long, long long>> tl;
	for (long long i = 0; i < m; ++i)
	{
		long long h; cin >> h;
		long long mmin = n + 2, mmax = -1;
		for (long long j = 0; j < h; ++j)
		{
			long long k; cin >> k;
			mmin = min(mmin, k);
			mmax = max(mmax, k);
		}
		tl.insert({ mmin, i * 2 });
		tl.insert({ mmax, i * 2 + 1 });
	}
	long long K; cin >> K;
	auto it1 = tl.begin(), it2 = tl.begin();
	vector<long long> b(m), e(m);
	long long count = 0, maxx = -1, l = 1;
	while (it1 != tl.end())
	{
		while (it2 != tl.end() && (it2->first - it1->first + 1) <= K)
		{
			if (it2->second % 2 == 0)
				b[it2->second / 2] = 1;
			else
				e[it2->second / 2] = 1;
			if ((b[it2->second / 2] == 1) && (e[it2->second / 2] == 1))
				++count;
			++it2;
		}
		if (count > maxx)
		{
			maxx = count;
			l = it1->first;
		}
		if ((b[it1->second / 2] == 1) && (e[it1->second / 2] == 1))
			--count;
		if (it1->second % 2 == 0)
			b[it1->second / 2] = 0;
		else
			e[it1->second / 2] = 0;
		++it1;
	}
	l = min(l, n - K + 1);
	cout << maxx << '\n' << l << ' ' << l + K - 1;

	return 0;
}