#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n; ++n;
	vector<int> a(n);
	for (auto& i : a) cin >> i;

	vector<int> cnt(31918903 + 2);
	for (auto& i : a)
		if (i != 0)
			++cnt[i + 1];

	for (int i = 1; i < cnt.size(); ++i)
		cnt[i] += cnt[i - 1];

	vector<int> nxt(n);
	for (int i = 0; i < n; ++i)
	{
		if (a[i] == 0)
		{
			nxt[0] = i;
			continue;
		}

		nxt[++cnt[a[i]]] = i;
	}

	for (int i = nxt[0]; i != 0; i = nxt[i])
		cout << a[nxt[i]] << ' ';
	cout << '\n';

	return 0;
}