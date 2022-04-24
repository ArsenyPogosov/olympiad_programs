#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, q; cin >> n >> q;

	vector<int> a(n), b(n);

	for (int i = 0; i < n; ++i)
		cin >> a[i], b[--a[i]] = i;

	int res = 1;
	for (int i = 1; i < n; ++i)
		res += (b[i] < b[i - 1]);

	while (q--)
	{
		int x, y; cin >> x >> y; --x; --y;
		set<int> dif{ a[x], a[x] + 1, a[y], a[y] + 1 };
		for (auto&i: dif)
			res -= ((i > 0) && (i < n) && (b[i] < b[i - 1]));
		swap(b[a[x]], b[a[y]]);
		swap(a[x], a[y]);
		for (auto& i : dif)
			res += ((i > 0) && (i < n) && (b[i] < b[i - 1]));

		cout << res << '\n';
	}

	return 0;
}