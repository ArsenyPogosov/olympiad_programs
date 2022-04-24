#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s; cin >> s;
	vector<int> c('Z' - 'A' + 1);
	for (auto& i : s) ++c[i - 'A'];
	string res = "";
	bool pain = false;
	char wypain;
	for (char i = 'A'; i <= 'Z'; ++i)
	{
		if (c[i - 'A'] % 2)
		{
			if (pain)
			{
				cout << "NO SOLUTION\n";
				return 0;
			}
			pain = true;
			wypain = i;
		}
		res += string(c[i - 'A'] / 2, i);
	}
	cout << res;
	if (pain) cout << wypain;
	reverse(res.begin(), res.end());
	cout << res << '\n';

	return 0;
}