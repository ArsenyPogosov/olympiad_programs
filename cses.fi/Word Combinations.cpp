#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const int p = 1e9 + 7;

struct node
{
	bool term;
	map<char, node*> p;
};

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	string s; cin >> s >> m; n = s.size();
	node *root = new node;
	while (m--)
	{
		string h; cin >> h;
		node *it = root;
		for (auto& i : h)
		{
			if (!it->p[i])
				it->p[i] = new node();
			it = it->p[i];
		}
		it->term = true;
	}
	vector<int> dp(n + 1); dp[0] = 1;
	for (int i = 0; i < n; ++i)
	{
		node* it = root;
		for (int j = i; j < n; ++j)
		{
			if (!it->p[s[j]])
				break;
			it = it->p[s[j]];
			if (it->term)
				dp[j + 1] += dp[i], dp[j + 1] %= p;
		}
	}
	cout << dp[n] << '\n';

	return 0;
}