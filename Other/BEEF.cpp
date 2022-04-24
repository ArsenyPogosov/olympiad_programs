#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int dist(char a, char b)
{
	int x, y;
	if ('0' <= a && a <= '9')
		x = a - '0';
	else
		x = a - 'A' + 10;
	if ('0' <= b && b <= '9')
		y = b - '0';
	else
		y = b - 'A' + 10;

	if (x > y) swap(x, y);

	return min(y - x, 16 + x - y);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string s; cin >> s;
	int n = s.size();
	int m; cin >> m; ++m;

	if (n < 4)
	{
		cout << 0 << '\n';
		return 0;
	}

	vector<int> a(m), b(m), c(m), d(m);

	for (int i = n - 4; i >= 0; --i)
	{
		vector<int> res = a;

		int cost = 0;
		cost += dist(s[i + 0], 'B');
		cost += dist(s[i + 1], 'E');
		cost += dist(s[i + 2], 'E');
		cost += dist(s[i + 3], 'F');

		for (int j = cost; j < m; ++j)
			res[j] = max(res[j], d[j - cost] + 1);
		swap(c, d);
		swap(b, c);
		swap(a, b);
		a = res;
	}

	cout << *max_element(a.begin(), a.end()) << '\n';

	return 0;
}