#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	string s; getline(cin, s);
	while (n--)
	{
		getline(cin, s);
		int m = s.size();
		for (int i = 0; i < m; ++i)
		{
			if ((s[i] == ':' || s[i] == '-') && (i > 0) && (s[i - 1] != ' '))
				cout << ' ';
			cout << s[i];
			if ((s[i] == ':' || s[i] == '-') && (i < m - 1) && (s[i + 1] != ' ') && (!(s[i + 1] == ':' || s[i + 1] == '-')))
				cout << ' ';
		}
		cout << '\n';
	}

	return 0;
}