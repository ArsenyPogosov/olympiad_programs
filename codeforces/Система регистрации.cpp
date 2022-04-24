#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

unordered_map<string, int> cnt;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string s; cin >> s;
		if (!cnt[s])
			cout << "OK\n";
		else
			cout << s << cnt[s] << '\n';
		++cnt[s];
	}
		

	return 0;
}