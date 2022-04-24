#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long n, m;

vector<long long> p, sz;

long long get(long long x)
{
	if (p[x] == -1) return x;
	return p[x] = get(p[x]);
}

bool unite(long long x, long long y)
{
	x = get(x); y = get(y);
	if (x == y) return false;

	if (sz[y] > sz[x]) swap(x, y);
	p[y] = x;
	sz[x] += sz[y];
	return true;
}

vector<long long> cost;

void init()
{
	cost.resize(m);
	for (auto& i : cost)
		i = rand() * 1ll * RAND_MAX * RAND_MAX * RAND_MAX + rand() * 1ll * RAND_MAX * RAND_MAX + rand() * 1ll * RAND_MAX + rand();
}

long long badcnt = 0;
vector<long long> aset, bset;

bool gd(long long x)
{
	return aset[x] == bset[x];
}

void merge(long long x, long long y)
{
	badcnt -= !gd(x);
	badcnt -= !gd(y);
	aset[x] ^= aset[y];
	bset[x] ^= bset[y];
	aset[y] = aset[x];
	bset[y] = bset[x];
	badcnt += !gd(x);
}

void changea(long long x, long long ws, long long nw)
{
	badcnt -= !gd(x);
	aset[x] ^= cost[ws] ^ cost[nw];
	badcnt += !gd(x);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	srand(228 + 1337);
	long long q; cin >> n >> q;
	vector<long long> a(n);
	for (auto& i : a) cin >> i;

	vector<long long> b(n); iota(b.begin(), b.end(), 0);
	sort(b.begin(), b.end(), [&](long long x, long long y) { return a[x] < a[y]; });
	long long prev = -1; m = -1;
	for (auto& i : b)
	{
		if (prev < a[i])
		{
			prev = a[i];
			++m;
		}
		i = a[i] = m;
	}
	++m;

	p.resize(n, -1);
	sz.resize(n, 1);

	init();
	aset.resize(n); bset.resize(n);
	for (long long i = 0; i < n; ++i)
	{
		aset[i] = cost[a[i]];
		bset[i] = cost[b[i]];
		badcnt += !gd(i);
	}

	while (q--)
	{
		long long h; cin >> h;
		if (h == 1)
		{
			long long x, y; cin >> x >> y; --x; --y;
			changea(get(x), a[x], a[y]);
			changea(get(y), a[y], a[x]);
			swap(a[x], a[y]);
		}
		if (h == 2)
		{
			long long x, y; cin >> x >> y; --x; --y;
			if (get(x) == get(y)) continue;
			merge(get(x), get(y));
			unite(x, y);
		}
		if (h == 3)
		{
			cout << (badcnt ? "NE" : "DA") << '\n';
		}
		if (h == 4)
		{
			long long parcnt = 0;
			for (long long i = 0; i < n; ++i)
				for (long long j = i + 1; j < n; ++j)
					if (get(i) != get(j) && !gd(get(i)) && !gd(get(j)) && !(aset[get(i)] ^ aset[get(j)] ^ bset[get(i)] ^ bset[get(j)]))
						++parcnt;

			cout << parcnt << '\n';
		}
	}

	return 0;
}