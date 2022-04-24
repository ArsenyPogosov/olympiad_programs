#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long p1 = 1e9 + 9;
const long long p2 = 1e7 + 7;
const long long t1 = 43;
const long long t2 = 43;

vector<long long> qpowtres1;
vector<long long> qpowtres2;

long long qpowt1(long long k)
{
	if (k == 0) return 1;
	if (qpowtres1[k] != 0)
		return qpowtres1[k];

	long long res = qpowt1(k / 2);
	return qpowtres1[k] = (res * res % p1 * (k % 2 ? t1 : 1)) % p1;
}
long long qpowt2(long long k)
{
	if (k == 0) return 1;
	if (qpowtres2[k] != 0)
		return qpowtres2[k];

	long long res = qpowt2(k / 2);
	return qpowtres2[k] = (res * res % p2 * (k % 2 ? t2 : 1)) % p2;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	srand(time(0) + 227 + rand());

	int n, m; cin >> n >> m;

	qpowtres1.resize(n + 1);
	for (int i = 1; i <= n; ++i)
		qpowtres1[i] = qpowtres1[i - 1] * t1 % p1;
	qpowtres2.resize(n + 1);
	for (int i = 1; i <= n; ++i)
		qpowtres2[i] = qpowtres2[i - 1] * t2 % p2;

	vector<long long> hsh1(n), hsh2(n);
	vector<pair<int, int>> edge(m);
	for (auto& i : edge)
	{
		cin >> i.first >> i.second; --i.first; --i.second;
		hsh1[i.first] = (hsh1[i.first] + qpowt1( (i.second + 228) % n + 1));
		hsh2[i.first] = (hsh2[i.first] + qpowt2( (i.second + 1337) % n + 1));
		hsh1[i.second] = (hsh1[i.second] + qpowt1( (i.first + 228) % n + 1));
		hsh2[i.second] = (hsh2[i.second] + qpowt2( (i.first + 1337) % n + 1));
	}

	for (auto& i : hsh1) i %= p1;
	for (auto& i : hsh2) i %= p2;

	long long res = 0;
	unordered_map<string, int> cnt;
	for (int i = 0; i < n; ++i)
		res += cnt[to_string(hsh1[i]) + ',' + to_string(hsh2[i])]++;

	for (auto& i : edge)
		if ((hsh1[i.first] + qpowt1( (i.first + 228) % n + 1)) % p1 == (hsh1[i.second] + qpowt1( (i.second + 228) % n + 1)) % p1)
			if ((hsh2[i.first] + qpowt2( (i.first + 1337) % n + 1)) % p2 == (hsh2[i.second] + qpowt2( (i.second + 1337) % n + 1)) % p2)
				++res;

	cout << res << '\n';

	return 0;
}