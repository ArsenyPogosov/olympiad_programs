#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, t, c; cin >> n >> t >> c;
	int BadGuy = -1, count = 0;
	for (int i = 0; i < n; ++i)
	{
		int h; cin >> h;
		if (h > t)
		{
			count += max(0, i - BadGuy - 1 - c + 1);
			BadGuy = i;
		}
	}
	count += max(0, n - BadGuy - 1 - c + 1);
	cout << count << '\n';

	return 0;
}