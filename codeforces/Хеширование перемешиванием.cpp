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

int main()
{
	int t; cin >> t;
	for (int tt = 0; tt < t; ++tt)
	{
		string p, s; cin >> s >> p;
		vector<int> cnt('z' - 'a' + 5);
		for (auto& i : s) ++cnt[i - 'a'];
		bool res = false;
		for (int i = 0; i < int(p.size()) - int(s.size()) + 1; ++i)
		{
			vector<int> cnt2('z' - 'a' + 5);
			for (int j = 0; j < s.size(); ++j) 
				++cnt2[p[i + j] - 'a'];
			bool f = false;
			for (int j = 0; j < cnt.size(); ++j) if (cnt[j] != cnt2[j]) { f = true; break; }
			if (f) continue;
			res = true;
			break;
		}
		cout << (res ? "YES\n" : "NO\n");
	}

	return 0;
}