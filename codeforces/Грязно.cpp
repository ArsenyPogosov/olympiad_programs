//source: https://codeforces.com/contest/1261/problem/A
//status: coding

#include <bits/stdc++.h>
using namespace std;
//#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif
#pragma endregion

void SwAp(string& s, int l, int r)
{
	for (int i = l; i < r - (i - l); ++i)
		swap(s[i], s[r - (i - l)]);
}

int main()
{
	int tt; cin >> tt;
	for (int ttt = 0; ttt < tt; ++ttt)
	{
		int n, k; cin >> n >> k;
		string s; cin >> s;
		vector<pair<int, int>> ans;
		for (int i = 0; i < k * 2 - 2; i += 2)
		{
			int j;
			for (j = i; j < n; ++j)
				if (s[j] == '(') break;
			ans.push_back({ i + 1, j + 1 });
			SwAp(s, i, j);
			for (j = i + 1; j < n; ++j)
				if (s[j] == ')') break;
			ans.push_back({ i + 2, j + 1 });
			SwAp(s, i + 1, j);
		}
		for (int i = k * 2 - 2; i < n; i += 1)
		{
			int j;
			for (j = i; j < n; ++j)
				if (s[j] == (i <= (n - 1 + k * 2 - 2) / 2 ? '(' : ')')) break;
			ans.push_back({ i + 1, j + 1 });
			SwAp(s, i, j);
		}
		cout << ans.size() << '\n';
		for (auto& i : ans)
			cout << i.first << ' ' << i.second << '\n';
	}

	return 0;
}