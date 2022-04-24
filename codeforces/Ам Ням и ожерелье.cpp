#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<int> p;
void pfunc(string s)
{
	int n = s.size();
	p.assign(n, 0);
	for (int i = 1; i < n; ++i)
	{
		p[i] = p[i - 1];
		while (p[i] && s[p[i]] != s[i]) p[i] = p[p[i] - 1];
		if (s[p[i]] == s[i]) ++p[i];
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	string s; cin >> s; pfunc(s);
	for (int i = 0; i < n; ++i)
	{
		int d = i + 1 - p[i];
		if (d == 0) { cout << 0; continue; }
		if (!((i + 1) % ((k + 1)*d))) { cout << 1; continue; }
		int x = (i + 1) / d, y = x / k;
		if (y == 0) { cout << 0; continue; }
		cout << ((i + 1) / (y * d) == k);
	}
	cout << '\n';

	return 0;
}