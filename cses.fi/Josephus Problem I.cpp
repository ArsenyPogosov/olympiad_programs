#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;

	list<int> a;
	for (int i = 0; i < n; ++i)
		a.push_back(i);

	auto it = a.begin();
	while (a.size())
	{
		++it;
		if (it == a.end())
			it = a.begin();
		cout << *it + 1 << ' ';

		it = a.erase(it);
		if (it == a.end())
			it = a.begin();
	}
	cout << '\n';

	return 0;
}