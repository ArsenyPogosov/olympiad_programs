#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, x; cin >> n >> x;
	vector<int> w(n);
	for (auto& i : w) cin >> i;
	vector<int> used(1 << n, -1); used[0] = 0;
	queue<int> Q; Q.push(0);
	vector<set<int>> res(5);
	while (Q.size())
	{
		int mask = Q.front(); Q.pop();
		bool isterm = true;
		for (int i = 0; i < n; ++i)
			if (!(mask & (1 << i)))
			{
				int nmask = mask ^ (1 << i);
				if (used[nmask] == -1)
				{
					used[nmask] = used[mask] + w[i];
					if (used[nmask] <= x)
					{
						Q.push(nmask);
						isterm = false;
					}
				}
				else if (used[nmask] <= x)
					isterm = false;
			}
		if (isterm)
			res[0].insert(mask);
	}
	for (int i = 1; i < 5; ++i)
	{
		set<int> nxt;
		for (auto& j : res[i - 1])
			for (auto& k : res[i - 1])
			{
				if (k >= j) break;
				nxt.insert(j | k);
			}
		if (nxt.find((1 << n) - 1) != nxt.end())
			nxt = { (1 << n) - 1 };
		res[i] = nxt;
		if (res[i].size() == 0) res[i] = res[i - 1];
	}
	int c = 0;
	set<int> now{ 0 };
	for (int i = 4; i >= 0; --i)
	{
		set<int> nxt;
		for (auto& j : now)
			for (auto& k : res[i])
			{
				nxt.insert(j | k);
			}
		if (nxt.find((1 << n) - 1) == nxt.end())
		{
			now = nxt;
			c += (1 << i);
		}
	}
	cout << c + 1 << '\n';

	return 0;
}