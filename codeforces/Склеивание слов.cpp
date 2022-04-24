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
	bool operator==(const Hash &h) const { return (x == h.x) && (y == h.y); }
	bool operator!=(const Hash &h) const { return !(h == *this); }
	Hash operator+(const Hash &h) const { return Hash(x + h.x, y + h.y, max(size, h.size)); }
	Hash operator-(const Hash &h) const { return Hash(x - h.x + p, y - h.y + q, max(size, h.size)); }
	Hash operator<<(long long n) const 
	{ 
		return Hash((x * bpowp[n]) % p, (y* bpowq[n]) % q, size + n);
	}
	void concat(const Hash &h)
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

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	BuildBpow(1000009);
	int n; cin >> n;
	string s;
	for (int i = 0; i < n; ++i)
	{
		string ns; cin >> ns;
		int len = 0, blen = 0;
		Hash ssh = Hash(), nsph = Hash();
		while (len < s.size() && len < ns.size())
		{
			Hash h = ssh;
			ssh = Hash(s[s.size() - len - 1] - '0' + 1);
			ssh.concat(h);
			nsph.concat(Hash(ns[len] - '0' + 1));
			++len;
			if (ssh == nsph) blen = len;
		}
		s += ns.substr(blen, 1000000000);
	}
	cout << s;

	return 0;
}