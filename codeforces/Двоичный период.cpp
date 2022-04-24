#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s; int n = s.size();
		int t = true;
		for (int i = 0; i < n - 1; ++i)
			if (s[i] != s[i + 1])
			{
				t = false; break;
			}
		if (t)
			cout << s << '\n';
		else
		{
			for (int i = 0; i < n; ++i)
				cout << "01";
			cout << '\n';
		}
	}

	return 0;
}