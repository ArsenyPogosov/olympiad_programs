#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	double t = clock();

	int n; cin >> n;
	string s; cin >> s;

	vector<int> cnt('z' - 'a' + 1);
	for (auto& i : s)
		++cnt[i - 'a'];
	vector<int> cnt2 = cnt;

	string res;
	for (int i = 0; i < n; ++i)
	{
		int curr = s[i] - 'a';
		int take = -1, val = 1e9;
		for (int j = 0; j < 26; ++j)
		{
			if (j == curr) continue;
			if (cnt2[j] <= 0) continue;
			int cval = ((n - i) - cnt[j]) - cnt2[j];
			if (cval < val)
			{
				val = cval;
				take = j;
			}
		}
		if (take == -1)
		{
			cout << "Impossible\n";
			return 0;
		}

		res += 'a' + take;
		--cnt[curr];
		--cnt2[take];
	}

	cout << res << '\n';

	return 0;
}