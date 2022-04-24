#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

void add(int x, int y)
{
	cout << x << ' ' << y << '\n';
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n; ++n;
	cout << n * 7 + 1 << '\n';
	for (int i = 0; i < n; ++i)
	{
		int x = i * 2, y = i * 2;
		add(x, y);
		add(x + 1, y);
		add(x + 2, y);
		add(x, y + 1);
		add(x, y + 2);
		add(x + 2, y + 1);
		add(x + 1, y + 2);
	}
	add(2 * n, 2 * n);

	return 0;
}