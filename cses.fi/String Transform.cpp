#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s; cin >> s;
	int n = s.size();
	vector<int> nxt(n), count('z' - 'a' + 1), pos('z' - 'a' + 2);
	for (auto& i : s) 
		if (i != '#')
			++count[i - 'a'];
	partial_sum(count.begin(), count.end(), pos.begin() + 1);
	int start;
	for (int i = 0; i < n; ++i)
		if (s[i] != '#')
			nxt[pos[s[i] - 'a']++ + 1] = i;
		else
			nxt[0] = start = i;
	for (int i = 0; i < n - 1; ++i)
	{
		start = nxt[start];
		cout << s[start];
	}
	cout << '\n';

	return 0;
}