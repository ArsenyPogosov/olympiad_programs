#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int n, k; cin >> n >> k;
		string s; cin >> s; sort(s.begin(), s.end());
		cout << s[k - 1];
		if (s[0] == s[k - 1] && k < n)
		{
			if (s[k] == s[n - 1])
			{
				for (int i = 0; i < (n - k + k - 1) / k; ++i)
					cout << s[k];
			}
			else
				cout << s.substr(k, n);
		}
		cout << '\n';
	}

	return 0;
}