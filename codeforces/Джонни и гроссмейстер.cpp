#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long P = 1e9 + 7;
const long long aa = P - 1;

pair<long long, bool> ppow(long long a, long long b)
{
	if (b == 0) return { 1, false};
	if (b % 2 == 1)
	{
		auto res = ppow(a, b - 1);
		if (res.first > aa / a) res.second = true;
		res.first = ((res.first * a) % P + P) % P;
		return res;
	}
	auto res = ppow(a, b / 2);
	if (res.first != 0 && res.first > aa / res.first) res.second = true;
	res.first = ((res.first * res.first) % P + P) % P;
	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long t; cin >> t;
	while (t--)
	{
		long long n, p; cin >> n >> p;
		vector<long long> kk(n);
		for (auto& i : kk) cin >> i;
		sort(kk.begin(), kk.end());
		vector<pair<long long, long long>> k;
		int pv = -1, cnt = 0;
		for (int i = n - 1; i >= 0; --i)
		{
			if (kk[i] == pv) ++cnt;
			else
			{
				if (pv != -1)
					k.emplace_back(pv, cnt);
				pv = kk[i];
				cnt = 1;
			}
		}
		if (pv != -1)
			k.emplace_back(pv, cnt);
		if (p == 1)
		{
			cout << n % 2 << '\n';
			continue;
		}
		long long div = 0; bool aaa = false; long long prev = k[0].first;
		for (auto&i: k)
		{
			long long change = prev - i.first; prev = i.first;
			auto chh = ppow(p, change);
			if (div != 0 && chh.second) aaa = true;
			if (chh.first != 0 && div > aa / chh.first)
				aaa = true;
			div = ((div * chh.first) % P + P) % P;
			if (aaa)
			{
				div -= i.second;
			}
			else
			{
				if (div <= i.second)
					div = (i.second - div) % 2;
				else
					div -= i.second;
			}
			div = (((div) % P) + P) % P;
		}
		div = (((div * ppow(p, prev).first) % P) + P) % P;
		cout << div << '\n';
	}

	return 0;
}