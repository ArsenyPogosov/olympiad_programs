//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/258598/problem/A_easy
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

const long long C = 300;

vector<long long> b;
vector<long long> sb;

struct block
{
	long long ind, l, r, add;
	block() {};
	block(long long _ind)
	{
		ind = _ind;
		l = C * ind;
		r = min(l + C - 1, (long long)b.size() - 1);
		add = 0;
		build();
	}
	void build()
	{
		copy(b.begin() + l, b.begin() + r + 1, sb.begin() + l);
		sort(sb.begin() + l, sb.begin() + r + 1);
	}
	long long Count(long long x)
	{
		x -= add;
		return lower_bound(sb.begin() + l, sb.begin() + r + 1, x) - sb.begin() - l;
	}
	long long Count(long long x, long long ll, long long rr)
	{
		x -= add;
		return count_if(b.begin() + max(l, ll), b.begin() + min(r, rr) + 1, [&](long long a) { return a < x; });
	}
	void Add(long long toadd)
	{
		add += toadd;
	}
	void Add(long long toadd, long long ll, long long rr)
	{
		ll = max(l, ll); rr = min(r, rr);
		for (long long i = ll; i <= rr; ++i) b[i] += toadd;
		build();
	}
};

vector<block> blocks;

long long Nb(long long x)
{
	return x / C;
}

long long Count(long long x, long long l, long long r)
{
	long long L = Nb(l), R = Nb(r), res = 0;
	res += blocks[L].Count(x, l, r);
	if (L != R) res += blocks[R].Count(x, l, r);
	for (long long i = L + 1; i <= R - 1; ++i) res += blocks[i].Count(x);
	return res;
}

void Add(long long toadd, long long l, long long r)
{
	long long L = Nb(l), R = Nb(r), res = 0;
	blocks[L].Add(toadd, l, r);
	if (L != R) blocks[R].Add(toadd, l, r);
	for (long long i = L + 1; i <= R - 1; ++i) blocks[i].Add(toadd);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n, q;
	cin >> n >> q;
	b.resize(n);
	sb.resize(n);
	for (auto& i : b) cin >> i;
	blocks.resize(n / C + 1);
	for (long long i = 0; i <= n / C; ++i) blocks[i] = block(i);

	for (long long i = 0; i < q; ++i)
	{
		long long reg, l, r, m;
		cin >> reg >> l >> r >> m;
		if (reg == 1) cout << Count(m, l - 1, r - 1) << '\n';
		if (reg == 2) Add(m, l - 1, r - 1);
	}

	return 0;
}