#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	while (m--)
	{
		int a, b; cin >> a >> b;
		cout << min(a, b) << ' ' << max(a, b) << '\n';
	}

	return 0;
}