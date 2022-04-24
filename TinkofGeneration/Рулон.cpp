#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int rf(bool rev, int mx, int tek)
{
	if (rev)
		return mx - tek - 1;
	return tek;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m;

	deque<list<int>> was(n), rwas(n);
	for (int i = 0; i < n; ++i)
		was[i].push_back(i + 1);
	for (int i = 0; i < n; ++i)
		rwas[i].push_back(i + 1);

	bool revc = false, revr = false;
	for (int ttt = 0; ttt < m; ++ttt)
	{
		bool aaa = false;

		int l; cin >> l;

		if (l < n - l)
		{
			aaa = true;
			l = n - l;
			revc ^= 1;
		}

		for (int i = n - 1; i >= l; --i)
		{
			if (revr)
				was[rf(revc, n, l * 2 - i - 1)].splice(was[rf(revc, n, l * 2 - i - 1)].begin(), rwas[rf(revc, n, i)]);
			else
				was[rf(revc, n, l * 2 - i - 1)].splice(was[rf(revc, n, l * 2 - i - 1)].end(), rwas[rf(revc, n, i)]);
			if (revr)
				rwas[rf(revc, n, l * 2 - i - 1)].splice(rwas[rf(revc, n, l * 2 - i - 1)].end(), was[rf(revc, n, i)]);
			else
				rwas[rf(revc, n, l * 2 - i - 1)].splice(rwas[rf(revc, n, l * 2 - i - 1)].begin(), was[rf(revc, n, i)]);
		}

		for (int i = n - 1; i >= l; --i)
		{
			if (!revc)
				was.pop_back();
			else
				was.pop_front();
			if (!revc)
				rwas.pop_back();
			else
				rwas.pop_front();
		}

		if (aaa)
			revr ^= 1;

		n = l;
	}

	int bi = 0;
	for (int i = 0; i < was.size(); ++i)
		if (was[i].size() > was[bi].size())
			bi = i;

	if (!revr)
		for (auto i = was[bi].begin(); i != was[bi].end(); ++i)
		{
			cout << *i << ' ';
		}
	else
		for (auto i = was[bi].end(); i != was[bi].begin(); --i)
		{
			cout << *prev(i) << ' ';
		}

	cout << '\n';

	for (int i = 0; i < n; ++i)
		if (!revr)
			cout << *was[rf(revc, n, i)].begin() << ' ';
		else
			cout << *prev(was[rf(revc, n, i)].end()) << ' ';
	cout << '\n';

	for (int i = 0; i < n; ++i)
		if (revr)
			cout << *was[rf(revc, n, i)].begin() << ' ';
		else
			cout << *prev(was[rf(revc, n, i)].end()) << ' ';
	cout << '\n';

	return 0;
}