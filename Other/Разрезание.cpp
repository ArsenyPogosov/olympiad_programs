#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<int> base(1000000);
vector<int> p(1000000);

pair<int, list<long long>> ans(long long n)
{
	if (n < 1000000) return { base[n], { n } };

	long long best = n;
	list<long long> path = { n };
	for (long long i = 10; i <= n; i *= 10)
	{
		auto res = ans(abs(n / i - (n % i)));
		if (best > res.first)
		{
			best = res.first;
			path = res.second;
			path.push_front(n);
		}
	}

	return { best, path };
}

int main()
{
	base[0] = 100000000;
	p[0] = -1;
	for (int i = 1; i < 1000000; ++i)
	{
		base[i] = i;
		p[i] = -1;
		for (int j = 10; j <= i; j *= 10)
			if (base[i] > base[abs(i / j - (i % j))])
			{
				p[i] = abs(i / j - (i % j));
				base[i] = base[p[i]];
			}
	}
	int t; cin >> t;
	while (t--)
	{
		long long n; cin >> n;
		auto res = ans(n);
		int count = 0;
		stringstream s;
		for (auto& i : res.second)
		{
			s << i << ' ';
			++count;
		}
		int t = p[*(--res.second.end())];
		while (t != -1)
		{
			s << t << ' '; t = p[t];
			++count;
		}
		cout << count << ' ' << s.str() << '\n';
	}

	return 0;
}