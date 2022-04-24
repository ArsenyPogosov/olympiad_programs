//source: 
//status: coding

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif
#pragma endregion

struct hashh {
	template <class T1, class T2>
	size_t operator()(const pair<T1, T2>& p) const
	{
		auto hash1 = hash<T1>{}(p.first);
		auto hash2 = hash<T2>{}(p.second);
		return hash1 ^ (hash2 + 5);
	}
};

long long DFS(long long a, long long b)
{
	if (b == 0) return a;
	return DFS(b, a % b);
}

int main()
{
	long long n;
	cin >> n;
	vector<long long> x(n);
	vector<long long> y(n);
	for (long long i = 0; i < n; ++i)
		cin >> x[i] >> y[i];
	long long count = 0;
	for (long long i = 0; i < n; ++i)
	{
		unordered_map<pair<long long, long long>, long long, hashh> xy;
		for (long long j = 0; j < n; ++j)
			if (i != j)
			{
				long long a = x[j] - x[i], b = y[j] - y[i];
				if (a != 0 && b != 0)
				{
					long long d = DFS(abs(a), abs(b));
					a /= d; b /= d;
					if (b < 0) { a *= -1; b *= -1; }
				}
				if (a == 0) b = 1;
				if (b == 0) a = 1;
				++xy[{a, b}];
			}
		long long ncount = 0;
		for (auto& i : xy)
		{
			long long na = -i.first.second, nb = i.first.first;
			if (nb < 0) { na *= -1; nb *= -1; }
			if (nb == 0) na = 1;
			if (xy.find({na, nb}) != xy.end())
				ncount += i.second * xy[{na, nb}];
		}
		count += ncount / 2;
	}
	cout << count;

	return 0;
}