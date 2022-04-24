#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

multiset<int, greater<int>> len;
set<pair<int, int>> seg;

void change(int i)
{
	auto it = --seg.lower_bound({ i + 1, 0 });
	pair<int, int> l = { -1, -1 }, t, r = { -1, -1 };
	if (it != seg.begin()) l = *prev(it);
	t = *it;
	if (next(it) != seg.end()) r = *next(it);
	len.erase(len.find(t.second - t.first + 1));
	seg.erase(t);
	if (t.first != i)
	{
		len.insert(i - t.first);
		seg.emplace(t.first, i - 1);
		t.first = i;
	}
	if (l.first != -1 && l.second + 1 == i)
	{
		len.erase(len.find(l.second - l.first + 1));
		seg.erase(l);
		t.first = l.first;
	}
	if (t.second != i)
	{
		len.insert(t.second - i);
		seg.emplace(i + 1, t.second);
		t.second = i;
	}
	if (r.second != -1 && r.first - 1 == i)
	{
		len.erase(len.find(r.second - r.first + 1));
		seg.erase(r);
		t.second = r.second;
	}
	len.insert(t.second - t.first + 1);
	seg.insert(t);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s; cin >> s;
	int n = s.size();
	for (int i = 0; i < n;)
	{
		int l = i, r;
		for (r = i + 1; r < n && s[l] == s[r]; ++r);
		len.insert(r - l);
		seg.emplace(l, r - 1);
		i = r;
	}
	int q; cin >> q;
	while (q--)
	{
		int i; cin >> i;
		change(i - 1);
		cout << *len.begin() << ' ';
	}
	cout << '\n';

	return 0;
}