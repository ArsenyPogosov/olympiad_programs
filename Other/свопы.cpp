#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int64_t n, m;

vector<int64_t> p, sz;

int64_t get(int64_t x)
{
	if (p[x] == -1) return x;
	return p[x] = get(p[x]);
}

bool unite(int64_t x, int64_t y)
{
	x = get(x); y = get(y);
	if (x == y) return false;

	if (sz[y] > sz[x]) swap(x, y);
	p[y] = x;
	sz[x] += sz[y];
	return true;
}

int64_t s = 37, P = 1e9 + 7;

int64_t pows(int64_t k)
{
	if (k == 0) return 1;

	int64_t res = pows(k / 2);
	return res * res % P * (k % 2 ? s : 1) % P;
}

int64_t badcnt = 0;
vector<int64_t> aset, bset;

int64_t res = 0;
unordered_map<int64_t, int64_t> cnt;

bool gd(int64_t x)
{
	return (aset[x] - bset[x]) % P == 0;
}

void add(int64_t& x, int64_t i)
{
	x = (x + pows(i)) % P;
}

void del(int64_t& x, int64_t i)
{
	x = ((x - pows(i)) % P + P) % P;
}

void Del(int64_t x, int64_t f)
{
	x = (x % P + P) % P;
	res -= cnt[x] * cnt[P-x];
	cnt[x] -= f;
	res += cnt[x] * cnt[P-x];
}

void Add(int64_t x, int64_t f)
{
	x = (x % P + P) % P;
	res -= cnt[x] * cnt[P - x];
	cnt[x] += f;
	res += cnt[x] * cnt[P - x];
}

void merge(int64_t x, int64_t y)
{
	if (!gd(x))
		Del(((aset[x] - bset[x]) % P + P) % P, sz[x]);
	if (!gd(y))
		Del(((aset[y] - bset[y]) % P + P) % P, sz[y]);
	badcnt -= !gd(x);
	badcnt -= !gd(y);

	aset[x] = aset[y] = (aset[x] + aset[y]) % P;
	bset[x] = bset[y] = (bset[x] + bset[y]) % P;

	badcnt += !gd(x);
	if (!gd(x))
		Add(((aset[x] - bset[x]) % P + P) % P, sz[x] + sz[y]);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	srand(228 + 1337 + time(0) + 1);
	int64_t q; cin >> n >> q;
	vector<int64_t> a(n);
	for (auto& i : a) cin >> i;

	vector<int64_t> b(n); iota(b.begin(), b.end(), 0);
	sort(b.begin(), b.end(), [&](int64_t x, int64_t y) { return a[x] < a[y]; });
	int64_t prev = -1; m = -1;
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

	aset.resize(n); bset.resize(n);
	for (int64_t i = 0; i < n; ++i)
	{
		add(aset[i], a[i]);
		add(bset[i], b[i]);
		if (!gd(i))
			Add(((aset[i] - bset[i]) % P + P) % P, sz[i]);
		badcnt += !gd(i);
	}

	while (q--)
	{
		int64_t h; cin >> h;
		if (h == 1)
		{
			int64_t x, y; cin >> x >> y; --x; --y;
			badcnt -= !gd(get(x));
			if (!gd(get(x)))
				Del(((aset[get(x)] - bset[get(x)]) % P + P) % P, sz[get(x)]);
			del(aset[get(x)], a[x]);
			add(aset[get(x)], a[y]);
			if (!gd(get(x)))
				Add(((aset[get(x)] - bset[get(x)]) % P + P) % P, sz[get(x)]);
			badcnt += !gd(get(x));
			badcnt -= !gd(get(y));
			if (!gd(get(y)))
				Del(((aset[get(y)] - bset[get(y)]) % P + P) % P, sz[get(y)]);
			del(aset[get(y)], a[y]);
			add(aset[get(y)], a[x]);
			if (!gd(get(y)))
				Add(((aset[get(y)] - bset[get(y)]) % P + P) % P, sz[get(y)]);
			badcnt += !gd(get(y));
			swap(a[x], a[y]);
		}
		if (h == 2)
		{
			int64_t x, y; cin >> x >> y; --x; --y;
			if (get(x) == get(y)) continue;
			merge(get(x), get(y));
			unite(x, y);
		}
		if (h == 3)
		{
			//cerr << "!";
			cout << (badcnt ? "NE" : "DA") << '\n';
		}
		if (h == 4)
		{
			//cerr << "!";
			cout << res << '\n';
		}
	}

	return 0;
}