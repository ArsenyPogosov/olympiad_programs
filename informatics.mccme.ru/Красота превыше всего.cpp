#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n);
	for (auto& i : a) cin >> i;
	vector<int> count(m + 1);
	int c = 0;
	pair<int, int> best = { 0, n + 1 };
	int l = 0, r = 0;
	for (; l < n;)
	{
		while (c < m)
		{
			if (r == n) break;
			if ((++count[a[r++]]) == 1) ++c;
		}
		if (c < m) break;
		if (best.second - best.first > r - l) best = { l, r };
		if ((--count[a[l++]]) == 0) --c;
	}
	cout << best.first + 1 << ' ' << best.second << '\n';
	cout << 'a' + 1;
	return 0;
}