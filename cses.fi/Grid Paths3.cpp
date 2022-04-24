#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const int p = 1e9 + 7;

pair<int, int> GCD(int a, int b)
{
	if (a == 0) return { 0, 1 };
	auto res = GCD(b % a, a);
	return { ((res.second - res.first * 1ll * (b / a)) % p + p) % p, res.first };
}

int obr(int x)
{
	return GCD(x, p).first;
}

vector<int> fact, ofact;

void init(int mx)
{
	fact.resize(mx + 1);
	fact[0] = 1; iota(fact.begin() + 1, fact.end(), 1);
	partial_sum(fact.begin(), fact.end(), fact.begin(), [&](int a, int b) {
		return (a * 1ll * b) % p; });
	ofact.resize(mx + 1);
	ofact[0] = 1; iota(ofact.begin() + 1, ofact.end(), 1);
	partial_sum(ofact.begin(), ofact.end(), ofact.begin(), [&](int a, int b) {
		return (a * 1ll * obr(b)) % p; });
}

int c(int n, int k)
{
	return (((fact[n] * 1ll * ofact[k]) % p) * 1ll * ofact[n - k]) % p;
}

int passcount(pair<int, int> a, pair<int, int> b)
{
	int x = b.first - a.first, y = b.second - a.second;
	if (y < 0) return 0;
	return c(x + y, x);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	init(n * 2);
	int m; cin >> m;
	vector<pair<int, int>> block(m);
	for (auto& i : block) cin >> i.first >> i.second, --i.first, --i.second;
	block.emplace_back(n - 1, n - 1);
	sort(block.begin(), block.end());
	vector<int> tres(m + 1);
	for (int i = 0; i <= m; ++i)
		tres[i] = passcount({ 0, 0 }, block[i]);
	for (int i = 0; i < m; ++i)
		for (int j = i + 1; j <= m; ++j)
		{
			tres[j] -= (tres[i] * 1ll * passcount(block[i], block[j])) % p;
			tres[j] = (tres[j] % p + p) % p;
		}
	cout << tres[m] << '\n';

	return 0;
}