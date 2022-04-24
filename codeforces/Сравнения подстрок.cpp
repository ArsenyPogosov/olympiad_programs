//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/259345/problems
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

const long long base = 97, p = 17352637, q = 80465021;

vector<long long> bpowp, bpowq;

void BuildBpow(long long n = 100000)
{
	bpowp.resize(n + 1);
	bpowq.resize(n + 1);
	bpowp[0] = 1;
	bpowq[0] = 1;
	for (long long i = 1; i <= n; ++i)
	{
		bpowp[i] = (bpowp[i - 1] * base) % p;
		bpowq[i] = (bpowq[i - 1] * base) % q;
	}
}

struct Hash
{
	long long x, y, size;
	Hash() { x = 0; y = 0; size = 0; }
	Hash(long long h) { x = h % p; y = h % q; size = 1; }
	Hash(long long h, long long _size) { x = h % p; y = h % q; size = _size; }
	Hash(long long _x, long long _y, long long _size) { x = _x % p; y = _y % q; size = _size; }
	bool operator==(const Hash& h) const { return (x == h.x) && (y == h.y); }
	bool operator!=(const Hash& h) const { return !(h == *this); }
	Hash operator+(const Hash& h) const { return Hash(x + h.x, y + h.y, max(size, h.size)); }
	Hash operator-(const Hash& h) const { return Hash(x - h.x + p, y - h.y + q, max(size, h.size)); }
	Hash operator<<(long long n) const
	{
		return Hash((x * bpowp[n]) % p, (y * bpowq[n]) % q, size + n);
	}
	void concat(const Hash& h)
	{
		*this = (*this << h.size);
		x = (x + h.x) % p;
		y = (y + h.y) % q;
	}
	void erasep(Hash h)
	{
		long long ns = size - h.size;
		h = h << (ns);
		*this = *this - h;
		this->size = ns;
	}
};

long long n;
string mass;
vector<Hash> pref;

void BuildPref()
{
	pref.resize(n);
	pref[0] = Hash(mass[0] - 'a' + 1);
	for (long long i = 1; i < n; ++i)
	{
		pref[i] = pref[i - 1];
		pref[i].concat(Hash(mass[i] - 'a' + 1));
	}
}

Hash seg(long long l, long long r)
{
	Hash res = pref[r];
	res.erasep((l > 0 ? pref[l - 1] : Hash()));
	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	cin >> mass; n = mass.size();
	BuildBpow(n + 1);
	BuildPref();
	long long m; cin >> m;
	for (long long i = 0; i < m; ++i)
	{
		long long a, b, c, d; cin >> a >> b >> c >> d; --a; --b; --c; --d;
		cout << (seg(a, b) == seg(c, d) ? "Yes" : "No") << '\n';
	}

	return 0;
}