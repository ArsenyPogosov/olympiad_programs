//source: 
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

struct man
{
	long long t, a, ind;
	man() : t(0), a(0), ind(0) {};
	man(long long t, long long a, long long ind) : t(t), a(a), ind(ind) {};
};

struct gr1
{
	bool operator()(const man &a, const man &b) const
	{
		return (a.ind < b.ind);
	}
};

struct gr2
{
	bool operator()(const man &a, const man &b) const
	{
		if (a.a < b.a) return true;
		return (a.a == b.a) && (a.ind < b.ind);
	}
};

int main()
{
	long long n, m; cin >> n >> m;
	vector<man> men(n);
	for (long long i = 0; i < n; ++i) { cin >> men[i].t >> men[i].a; men[i].ind = i; --men[i].a;  }
	sort(men.begin(), men.end(), [](man a, man b) {
		if (a.t < b.t) return true;
		return (a.t == b.t) && (a.ind < b.ind);
		});
	long long time = 0, it = 0, targ = -2;
	set<man, gr1> order;
	set<man, gr2> itman;
	vector<long long> ans(n);
	long long count = n;
	for (long long i = 0; count > 0;)
	{
		long long dt;
		man tm;
		if (i < n)
		{
			tm = men[i];
			dt = tm.t - time;
		}
		else
		{
			dt = 1000000000;
		}
		if (dt == 0)
		{
			order.insert(tm);
			itman.insert(tm);
			++i;
			continue;
		}
		if (targ == -2)
		{
			if (order.size() != 0)
			{
				targ = order.begin()->a;
				continue;
			}
			time += dt;
			continue;
		}
		if (targ == -1)
		{
			long long ddt = min(dt, it);
			while (itman.size())
			{
				man nm = *itman.begin();
				if (nm.a > it) break;
				itman.erase(itman.begin());
				order.erase(order.find(nm));
				ans[nm.ind] = time + it;
				--count;
			}
			time += ddt;
			it -= ddt;
			if (it == 0) 
				targ = -2;
			continue;
		}
		if (targ >= 0)
		{
			long long ddt = min(dt, targ - it);
			time += ddt;
			it += ddt;
			if (it == targ) targ = -1;
			continue;
		}
	}
	for (auto& i : ans) cout << i << ' ';
	cout << '\n';

	return 0;
}