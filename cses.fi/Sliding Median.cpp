#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	vector<int> x(n);
	for (auto& i : x) cin >> i;
	multiset<int> s1, s2;
	for (int i = 0; i < k; ++i) s2.insert(x[i]);
	for (int i = 0; i < (k - 1) / 2; ++i)
	{
		s1.insert(*s2.begin());
		s2.erase(s2.begin());
	}
	cout << *s2.begin();
	for (int i = k; i < n; ++i)
	{
		s1.insert(x[i]);
		auto it = s1.find(x[i - k]);
		if (it != s1.end()) 
			s1.erase(it);
		else
			s2.erase(s2.find(x[i - k]));
		while (s1.size() > (k - 1) / 2 || (s1.size() && *prev(s1.end()) > * s2.begin()))
		{
			s2.insert(*prev(s1.end()));
			s1.erase(prev(s1.end()));
		}
		while (s1.size() < (k - 1) / 2)
		{
			s1.insert(*s2.begin());
			s2.erase(s2.begin());
		}
		while (s1.size() > (k - 1) / 2 || (s1.size() && *prev(s1.end()) > * s2.begin()))
		{
			s2.insert(*prev(s1.end()));
			s1.erase(prev(s1.end()));
		}
		while (s1.size() < (k - 1) / 2)
		{
			s1.insert(*s2.begin());
			s2.erase(s2.begin());
		}
		while (s1.size() > (k - 1) / 2 || (s1.size() && *prev(s1.end()) > * s2.begin()))
		{
			s2.insert(*prev(s1.end()));
			s1.erase(prev(s1.end()));
		}
		while (s1.size() < (k - 1) / 2)
		{
			s1.insert(*s2.begin());
			s2.erase(s2.begin());
		}
		cout << ' ' << *s2.begin();
	}
	cout << '\n';

	return 0;
}