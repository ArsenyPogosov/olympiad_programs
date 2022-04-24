#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	vector<int> move(k);
	for (auto& i : move) cin >> i;
	vector<char> win(n + 1);
	for (int i = 1; i <= n; ++i)
		for (auto&j: move)
			if (i - j >= 0 && !win[i - j])
			{
				win[i] = true;
				break;
			}
	for (int i = 1; i <= n; ++i)
		cout << (win[i] ? 'W' : 'L');
	cout << '\n';

	return 0;
}