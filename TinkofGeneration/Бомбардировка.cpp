#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

string ts(pair<long long, long long> d)
{
	string res = to_string(d.first);
	if (d.second == d.first + 1)
	{
		return res + ',' + to_string(d.second);
	}
	if (d.second != d.first)
		res += ".." + to_string(d.second);

	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long n, l; cin >> l >> n;
	vector<pair<long long, long long>> a(n);
	long long tl = 0;
	for (auto& i : a)
	{
		cin >> i.first; i.second = i.first;
		tl += ts(i).size();
	}
	sort(a.begin(), a.end());

	while (tl + 2 + a.size() - 1 > l && a.size())
	{
		long long bi = -1, bres = 1e18;
		for (long long i = 0; i < a.size() - 1; ++i)
		{
			long long tres = a[i + 1].second - a[i].first + 1 - (a[i].second - a[i].first + 1) - (a[i + 1].second - a[i + 1].first + 1);
			tres += rand() % 10;
			if (tres < bres)
			{
				bi = i;
				bres = tres;
			}
		}
		tl -= ts(a[bi]).size() + ts(a[bi + 1]).size();
		a[bi].second = a[bi + 1].second;
		for (long long i = bi + 1; i < a.size() - 1; ++i)
			a[i] = a[i + 1];
		a.pop_back();
		tl += ts(a[bi]).size();
	}

	cout << '[';
	for (long long i = 0; i < (long long)(a.size()) - 1; ++i)
		cout << ts(a[i]) << ',';
	if (a.size())
		cout << ts(a.back()) << "]\n";

	return 0;
}