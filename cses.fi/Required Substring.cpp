#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long p = 1e9 + 7;

long long n, alf = 'z' - 'a' + 1;
string s;

vector<long long> pi;

void preffunc()
{
	pi.resize(n);
	pi[0] = 0;
	for (long long i = 1; i < n; ++i)
	{
		pi[i] = pi[i - 1];
		while (pi[i] > 0 && s[pi[i]] != s[i]) pi[i] = pi[pi[i] - 1];
		pi[i] += (s[pi[i]] == s[i]);
	}
}

vector<vector<long long>> res;

long long ans(long long m, long long l)
{
	if (l == n)
		return 0;
	if (m == 0)
		return 1;
	if (res[m][l] != -1) return res[m][l];
	vector<int> nxt(alf);
	int k = l;
	while (true)
	{
		if (nxt[s[k]-'A'] == 0) nxt[s[k]-'A'] = k + 1;
		if (k == 0) break;
		k = pi[k - 1];
	}
	res[m][l] = 0;
	for (auto& i : nxt) res[m][l] += ans(m - 1, i);
	res[m][l] %= p;
	return res[m][l];
}

long long ppow(long long a, long long k)
{
	if (k == 0) return 1;
	if (k % 2 == 1) return (ppow(a, k - 1) * a) % p;
	long long res = ppow(a, k / 2);
	return (res * res) % p;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long m; cin >> m >> s; n = s.size();
	preffunc();
	res.resize(m + 1, vector<long long>(n, -1));
	cout << ((ppow(alf, m) - ans(m, 0)) % p + p) % p << '\n';

	return 0;
}