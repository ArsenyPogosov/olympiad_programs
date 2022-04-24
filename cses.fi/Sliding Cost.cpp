#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	vector<int> x(n);
	for (auto& i : x) cin >> i;
	long long ss1 = 0, ss2 = 0;
	multiset<int> s1, s2;
	for (int i = 0; i < k; ++i) { ss2 += x[i]; s2.insert(x[i]);	}
	for (int i = 0; i < (k - 1) / 2; ++i)
	{
		ss1 += *s2.begin(); s1.insert(*s2.begin());
		ss2 -= *s2.begin(); s2.erase(s2.begin());
	}
	cout << (1ll*(*s2.begin()) * ((k - 1) / 2) - ss1 + ss2 - 1ll*(*s2.begin()) * (k - (k - 1) / 2));
	for (int i = k; i < n; ++i)
	{
		s1.insert(x[i]); ss1 += x[i];
		auto it = s1.find(x[i - k]);
		if (it != s1.end())
		{
			s1.erase(it); ss1 -= x[i - k];
		}
		else
		{
			s2.erase(s2.find(x[i - k])); ss2 -= x[i - k];
		}
		while (s1.size() > (k - 1) / 2 || (s1.size() && *prev(s1.end()) > * s2.begin()))
		{
			ss2 += *prev(s1.end()); s2.insert(*prev(s1.end()));
			ss1 -= *prev(s1.end()); s1.erase(prev(s1.end()));
		}
		while (s1.size() < (k - 1) / 2)
		{
			ss1 += *s2.begin(); s1.insert(*s2.begin());
			ss2 -= *s2.begin(); s2.erase(s2.begin());
		}
		while (s1.size() > (k - 1) / 2 || (s1.size() && *prev(s1.end()) > * s2.begin()))
		{
			ss2 += *prev(s1.end()); s2.insert(*prev(s1.end()));
			ss1 -= *prev(s1.end()); s1.erase(prev(s1.end()));
		}
		while (s1.size() < (k - 1) / 2)
		{
			ss1 += *s2.begin(); s1.insert(*s2.begin());
			ss2 -= *s2.begin(); s2.erase(s2.begin());
		}
		while (s1.size() > (k - 1) / 2 || (s1.size() && *prev(s1.end()) > * s2.begin()))
		{
			ss2 += *prev(s1.end()); s2.insert(*prev(s1.end()));
			ss1 -= *prev(s1.end()); s1.erase(prev(s1.end()));
		}
		while (s1.size() < (k - 1) / 2)
		{
			ss1 += *s2.begin(); s1.insert(*s2.begin());
			ss2 -= *s2.begin(); s2.erase(s2.begin());
		}
		cout << ' ' << (1ll * (*s2.begin()) * ((k - 1) / 2) - ss1 + ss2 - 1ll * (*s2.begin()) * (k - (k - 1) / 2));
	}
	cout << '\n';

	return 0;
}