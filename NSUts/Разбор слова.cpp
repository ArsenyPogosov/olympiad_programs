#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int p = 845397193, t = 43, mxn = 1e5 + 10;
vector<int> tpow(mxn);

int get(vector<int>& hash, int l, int r)
{
	return ((hash[r] - ((l > 0 ? hash[l - 1] : 0) * 1ll * tpow[r - l + 1])) % p + p) % p; 
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	tpow[0] = 1;
	for (int i = 1; i < mxn; ++i)
		tpow[i] = (tpow[i - 1] * 1ll * t) % p;
	int a, b, c; cin >> a >> b >> c;
	vector<int> ahash(a + 1), alen(a + 1), bhash(b + 1), blen(b + 1), chash(c + 1), clen(c + 1);
	for (int i = 0; i < a; ++i)
	{
		string s; cin >> s;
		int n = s.size();
		alen[i] = n;
		int resh = 0;
		for (int j = 0; j < n; ++j)
		{
			resh = (resh + tpow[n - j - 1] * 1ll * (s[j] - 'a' + 1)) % p;
		}
		ahash[i] = resh;
	}
	for (int i = 0; i < b; ++i)
	{
		string s; cin >> s;
		int n = s.size();
		blen[i] = n;
		int resh = 0;
		for (int j = 0; j < n; ++j)
		{
			resh = (resh + tpow[n - j - 1] * 1ll * (s[j] - 'a' + 1)) % p;
		}
		bhash[i] = resh;
	}
	for (int i = 0; i < c; ++i)
	{
		string s; cin >> s;
		int n = s.size();
		clen[i] = n;
		int resh = 0;
		for (int j = 0; j < n; ++j)
		{
			resh = (resh + tpow[n - j - 1] * 1ll * (s[j] - 'a' + 1)) % p;
		}
		chash[i] = resh;
	}
	int n; cin >> n;
	while (n--)
	{
		string s; cin >> s;
		int l = s.size();
		vector<int> hash(l);
		hash[0] = (s[0] - 'a' + 1);
		for (int j = 1; j < l; ++j)
			hash[j] = (hash[j - 1] * 1ll * t + (s[j] - 'a' + 1)) % p;
		int res = 0;
		for (int i = 0; i <= a; ++i)
		{
			if (alen[i] > 0 && !(l >= alen[i] && get(hash, 0, alen[i] - 1) == ahash[i])) continue;
			for (int j = 0; j <= c; ++j)
			{
				if (clen[j] > 0 && !(l >= alen[i] + clen[j] && get(hash, l - clen[j], l - 1) == chash[j])) continue;
				for (int k = 0; k <= b; ++k)
				{
					if (blen[k] > 0 && !(l >= alen[i] + blen[k] + clen[j] && get(hash, l - clen[j] - blen[k], l - clen[j] - 1) == bhash[k])) continue;
					++res;
				}	
			}
		}
		cout << res << '\n';
	}

	return 0;
}