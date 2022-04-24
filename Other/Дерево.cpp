#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	map<int, int> vals{ {-1, n}, {1e9 + 1, n} };
	int a; cin >> a; vals[a] = --n;
	while (n--)
	{
		int a; cin >> a;
		auto x = --vals.lower_bound(a), y = vals.upper_bound(a);
		cout << (x->second < y->second ? x->first : y->first) << '\n';
		vals[a] = n;
	}

	return 0;
}