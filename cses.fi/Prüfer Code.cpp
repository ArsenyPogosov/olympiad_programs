#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> a(n - 2);
	for (auto& i : a) cin >> i, --i;
	vector<int> count(n);
	for (auto& i : a) ++count[i];
	set<int> free;
	for (int i = 0; i < n; ++i)
		if (count[i] == 0)
			free.insert(i);
	for (int i = 0; i < n - 2; ++i)
	{
		cout << *free.begin() + 1 << ' ' << a[i] + 1 << '\n';
		free.erase(free.begin());
		--count[a[i]];
		if (count[a[i]] == 0)
			free.insert(a[i]);
	}
	cout << *free.begin() + 1 << ' ' << *next(free.begin()) + 1 << '\n';

	return 0;
}