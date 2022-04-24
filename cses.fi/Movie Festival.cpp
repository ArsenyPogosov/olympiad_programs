#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> b(n), e(n), ord(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> b[i] >> e[i];
	}
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](int a, int b) {return e[a] < e[b]; });
	int count = 0, mnstart = 0;
	for (auto& i : ord)
	{
		if (b[i] < mnstart) continue;
		mnstart = e[i];
		++count;
	}
	cout << count << '\n';

	return 0;
}