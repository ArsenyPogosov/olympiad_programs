#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const int p = 239017;

vector<int> fact, ofact;

pair<int, int> Fact(int x)
{
	if (x == 0) return { 1, 0 };
	pair<int, int> res = Fact(x / p); res.second += x / p;
	res.first = (res.first * 1ll * fact[x % p]) % p;
	if ((x / p) % 2)
		res.first = p - res.first;

	return res;
}

pair<int, int> Ofact(int x)
{
	if (x == 0) return { 1, 0 };
	pair<int, int> res = Ofact(x / p); res.second -= x / p;
	res.first = (res.first * 1ll * ofact[x % p]) % p;
	if ((x / p) % 2)
		res.first = p - res.first;

	return res;
}

pair<int, int> mult(pair<int, int> a, pair<int, int> b)
{
	return { a.first * 1ll * b.first % p, a.second + b.second };
}

int c(int n, int k)
{
	pair<int, int> res = mult(Fact(n), mult(Ofact(k), Ofact(n - k)));
	if (res.second) return 0;
	return res.first;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	fact.resize(p);
	fact[0] = 1;
	for (int i = 1; i < p; ++i)
		fact[i] = (fact[i - 1] * 1ll * i) % p;
	ofact.resize(p);
	ofact[p - 1] = p - 1;
	for (int i = p - 2; i >= 0; --i)
		ofact[i] = (ofact[i + 1] * 1ll * (i + 1)) % p;

	int n; cin >> n;
	while (n--)
	{
		int m, k; cin >> m >> k;
		cout << c(m, k) << '\n';
	}

	return 0;
}