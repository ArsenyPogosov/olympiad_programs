#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;

	vector<int> a(n), b(m);
	for (auto& i : a) cin >> i;
	for (auto& i : b) cin >> i;

	vector<pair<int, int>> merge(n + m);

	int x = 0, y = 0;
	auto addx = [&]() {
		merge[x + y] = { 0, x };
		++x;
	};
	auto addy = [&]() {
		merge[x + y] = { 1, y };
		++y;
	};
	while (x + y < n + m)
	{
		if (y == m)
		{
			addx();
			continue;
		}
		if (x == n)
		{
			addy();
			continue;
		}

		if (a[x] <= b[y])
			addx();
		else
			addy();
	}

	stack<int> ants;
	vector<int> res(n, -1);
	for (auto& i : merge)
	{
		if (i.first == 0)
		{
			ants.push(i.second);
		}
		if (i.first == 1)
		{
			if (ants.size())
			{
				res[ants.top()] = i.second + 1;
				ants.pop();
			}
		}
	}

	for (auto& i : res)
		cout << i << '\n';

	return 0;
}