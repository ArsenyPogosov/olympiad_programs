#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		int n = s.size();
		vector<int> ps(n); ps[0] = s[0] - '0';
		for (int i = 1; i < n; ++i) ps[i] = ps[i - 1] + (s[i] - '0');
		int best = min(ps[n - 1], n - ps[n - 1]);
		for (int i = 0; i < n; ++i)
		{
			best = min(best, ps[i] + n - i - 1 - (ps[n - 1] - ps[i]));
			best = min(best, i + 1 - ps[i] + (ps[n - 1] - ps[i]));
		}
		cout << best << '\n';	
	}

	return 0;
}