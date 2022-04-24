#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	vector<long long> e(3), pos{0, 1, 2};
	for (auto& i : e) cin >> i;
	sort(pos.begin(), pos.end(), [&](int a, int b) { return e[a] < e[b]; });
	cout << "First" << endl;
	while (true)
	{
		vector<long long> pos{ 0, 1, 2 };
		sort(pos.begin(), pos.end(), [&](int a, int b) { return e[a] < e[b]; });
		cout << e[pos[2]] - e[pos[1]] << endl;
		int h; cin >> h;
		if (h == 0) return 0;
		e[h - 1] += e[pos[2]] - e[pos[1]];
	}

	return 0;
}