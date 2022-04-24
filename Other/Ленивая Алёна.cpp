#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long p = 1e9 + 9;
const long long t = 37;

unordered_map<long long, long long> qpowtres;

long long qpowt(long long k)
{
	if (k == 0) return 1;
	if (qpowtres[k] != 0)
		return qpowtres[k];

	long long res = qpowt(k / 2);
	return qpowtres[k] = (res * res % p * (k % 2 ? t : 1)) % p;
}

int n;
string s;

vector<long long> ph;

long long get(int l, int r)
{
	return ((ph[r] - ph[l] * qpowt(r - l)) % p + p) % p;
}

int compare(int l1, int r1, int l2, int r2)
{
	int l = 0, r = min(r1 - l1, r2 - l2) + 1;
	while (l + 1 < r)
	{
		int m = (l + r) / 2;
		if (get(l1, l1 + m) == get(l2, l2 + m))
			l = m;
		else
			r = m;
	}

	if (l >= min(r1 - l1, r2 - l2))
	{
		if (r1 - l1 == r2 - l2) return 0;
		return (r1 - l1 < r2 - l2 ? -1 : +1);
	}
	return (s[l1 + l] < s[l2 + l] ? -1 : +1);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	srand(time(0) + 1328 + rand());

	cin >> s;
	n = s.size();

	ph.resize(n + 1);
	for (int i = 0; i < n; ++i)
		ph[i + 1] = (ph[i] * t + (hash<char>()(s[i]) % ('z' - 'a' + 1)) + 2) % p;

	int m; cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int l1, r1, l2, r2; cin >> l1 >> r1 >> l2 >> r2;

		cout << compare(l1, r1 + 1, l2, r2 + 1) << '\n';
	}

	return 0;
}