//source: 
//status: coding

#include <bits/stdc++.h>
#include <unordered_map>
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
		int n; cin >> n;
		vector<string> order(n);
		unordered_map<string, int> m;
		int count = 0;
		for (auto& i : order)
		{
			cin >> i;
			if (m[i] != 0) ++count;
			++m[i];
		}
		cout << count << '\n';
		for (auto& i : order)
		{
			if (m[i] < 2)
				cout << i << '\n';
			else
			{
				--m[i];
				bool flag = true;
				for (int j = 0; j < 4 && flag; ++j)
					for (int nw = 0; nw < 10; ++nw)
					{
						string tek = i; tek[j] = '0' + nw;
						if (m[tek] == 0)
						{
							++m[tek];
							cout << tek << '\n';
							flag = false;
							break;
						}
					}
			}
		}
		cout << '\n';
	}

	return 0;
}