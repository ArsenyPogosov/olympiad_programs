#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const int p = 1e9 + 7;

pair<int, int> GCD(int a, int b)
{
	if (a == 0) return {0, 1};
	auto res = GCD(b % a, a);
	return { ((res.second - (b / a) * 1ll * res.first) % p + p) % p, res.first };
}

int obr(int x)
{
	return GCD(x, p).first;
}

vector<int> fact, ofact;

void build(int mx)
{
	fact.resize(mx + 1);
	fact[0] = 1; iota(fact.begin() + 1, fact.end(), 1);
	partial_sum(fact.begin(), fact.end(), fact.begin(), [&](int a, int b) { return (a * 1ll * b) % p; });
	ofact.resize(mx + 1);
	ofact[0] = 1; iota(ofact.begin() + 1, ofact.end(), 1);
	partial_sum(ofact.begin(), ofact.end(), ofact.begin(), [&](int a, int b) { return (a * 1ll * obr(b)) % p; });
}

int c(int n, int k)
{
	return (((fact[n] * 1ll * ofact[k]) % p) * 1ll * ofact[n - k]) % p;
}

int n;
string s;

vector<int> nxt;
vector<vector<int>> ans;

int res(int l, int r)
{
	if (l > r) return 1;
	if ((r - l + 1) % 2) return 0;
	if (ans[l][r] != -1) return ans[l][r];
	ans[l][r] = 0;
	for (int i = nxt[l]; i <= r; i = nxt[i])
		ans[l][r] += (((res(i + 1, r) * 1ll * res(l + 1, i - 1)) % p) * 1ll * c((r - l + 1) / 2, (r - i) / 2)) % p, 
		ans[l][r] %= p;
	return ans[l][r];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> s; n = s.size();
	build(n + 1);
	vector<int> pr('z' - 'a' + 1, -1);
	nxt.resize(n, 1e9);
	for (int i = 0; i < n; ++i)
	{
		if (pr[s[i] - 'a'] != -1)
			nxt[pr[s[i] - 'a']] = i;
		pr[s[i] - 'a'] = i;
	}
	ans.resize(n, vector<int>(n, -1));
	cout << res(0, n - 1) << '\n';

	return 0;
}