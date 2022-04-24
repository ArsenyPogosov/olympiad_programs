#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<int> cnt;
set<int> mex;

void add(int v)
{
	++cnt[v];
	if (cnt[v] == 1)
		mex.erase(v);
}

void remove(int v)
{
	--cnt[v];
	if (cnt[v] == 0)
		mex.insert(v);
}

void init(int n)
{
	cnt.assign(n + 1, 0);
	mex.clear();
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		vector<int> a(n), res;
		for (auto& i : a) cin >> i;
		init(n);
		for (int i = 0; i <= n; ++i) mex.insert(i);
		for (auto& i : a) add(i); 
		bool good = false;
		while(!good)
		{
			int x = *mex.begin();
			if (x != n)
			{
				res.push_back(x);
				remove(a[x]);
				a[x] = x;
				add(a[x]);
				continue;
			}
			good = true;
			for (int j = 0; j < n; ++j)
				if (a[j] != j)
				{
					res.push_back(j);
					remove(a[j]);
					a[j] = x;
					add(a[j]);
					good = false;
					break;
				}
		}
		cout << res.size() << '\n';
		for (auto& i : res) cout << i + 1 << ' ';
		cout << '\n';
	}

	return 0;
}