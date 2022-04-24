//source: 
//status: coding

#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
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

int main()
{
	unordered_map<string, bool> p;
	int n; cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int k; cin >> k;
		for (int j = 0; j < k; ++j)
		{
			string s; cin >> s; p[s] = true;
		}
	}
	int gg = p.size();
	cout << gg << ' ';
	int m; cin >> m;
	unordered_set<string> bg;
	for (int i = 0; i < m; ++i)
	{
		int k, count = 0; cin >> k;
		string last = "";
		for (int j = 0; j < k; ++j)
		{
			string s; cin >> s;
			if (!p[s])
			{
				++count;
				last = s;
			}
		}
		if (count == 1) bg.insert(last);
	}
	cout << bg.size() << ' ' << p.size() - bg.size() - gg;

	return 0;
}