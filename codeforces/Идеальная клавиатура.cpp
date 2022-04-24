//source: 
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

int N = 'z' - 'a' + 1;
vector<vector<int>> Graph;
vector<int> fire;
string res;

int main()
{
	int t; cin >> t;
	Graph.assign(N, vector<int>(N, false));
	fire.assign(N, false);
	while (t--)
	{
		string s; cin >> s; int n = s.size();
		for (auto& i : Graph)
			for (auto& j : i) j = false;
		for (int i = 0; i < n - 1; ++i)
		{
			Graph[s[i] - 'a'][s[i + 1] - 'a'] = true;
			Graph[s[i + 1] - 'a'][s[i] - 'a'] = true;
		}
		for (auto& i : fire) i = false;
		res = "";
		bool flagg = false;
		for (int i = 0; i < N; ++i)
		{
			int c = 0;
			for (auto& j : Graph[i]) if (j) ++c;
			if (c > 2)
			{
				cout << "NO\n";
				flagg = true;
				break;
			}
		}
		if (flagg) continue;
		for (int i = 0; i < N; ++i)
		{
			int c = 0;
			for (auto& j : Graph[i]) if (j) ++c;
			if (fire[i]) continue;
			if (c < 2)
			{
				int t = i, p = -1;
				while (true)
				{
					res += 'a' + t;
					fire[t] = true;
					bool flag = false;
					for (int j = 0; j < N; ++j)
						if (Graph[t][j] && j != p)
						{
							p = t;
							t = j;
							flag = true;
							break;
						}
					if (!flag) break;
				}
			}
		}
		bool flag = false;
		for (auto&i: fire)
			if (!i)
			{
				cout << "NO\n";
				flag = true;
				break;
			}
		if (!flag)
			cout << "YES\n" << res << '\n';
	}

	return 0;
}