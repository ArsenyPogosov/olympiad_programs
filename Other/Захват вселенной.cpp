#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long p1 = 1e9 + 9;
const long long p2 = 1e7 + 7;
const long long t1 = 43;
const long long t2 = 37;

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

	srand(time(0) + 288 + rand());

	int k; cin >> k;
	int n = (1 << k);

	qpowtres1.resize(n / 2 + 1);
	for (int i = 1; i <= n / 2; ++i)
		qpowtres1[i] = qpowtres1[i - 1] * t1 % p1;
	qpowtres2.resize(n / 2 + 1);
	for (int i = 1; i <= n / 2; ++i)
		qpowtres2[i] = qpowtres2[i - 1] * t2 % p2;

	vector<int> a(n);
	for (auto& i : a)
		cin >> i, i = min(i, n - 1 - i) * 37 % (n / 2);

	if (k == 1)
	{
		cout << "2\n";
		return 0;
	}

	long long res = n * 1ll * (n + 1) / 2;
	vector<map<pair<long long, long long>, int>> rcnt(4);
	rcnt[3][{0, 0}] = 1;
	vector<char> cnt(n / 2);
	long long curr1 = 0, curr2 = 0;
	for (int i = 0; i < n; ++i)
	{
		curr1 = ((curr1 - cnt[a[i]] * qpowt1(a[i])) % p1 + p1) % p1;
		curr2 = ((curr2 - cnt[a[i]] * qpowt2(a[i])) % p2 + p2) % p2;
		cnt[a[i]] = 1 - cnt[a[i]];
		curr1 = (curr1 + cnt[a[i]] * qpowt1(a[i])) % p1;
		curr2 = (curr2 + cnt[a[i]] * qpowt2(a[i])) % p2;
		res -= rcnt[i % 4][{curr1, curr2}]++;
	}

	cout << res << '\n';

	return 0;
}