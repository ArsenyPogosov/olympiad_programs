//source: https://codeforces.com/gym/102348/problem/E
//status: solved

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
	int n, m, k;
	cin >> n >> m >> k;
	set<pair<int, int>> a;
	for (int i = 1; i <= m; ++i)
	{
		int h;
		cin >> h;
		a.insert({ -h, i });
	}

	string res;
	int kk = 0, lc = -1;
	while (a.size())
	{
		auto t = a.begin();
		if (a.begin()->second != lc)
		{
			kk = 1;
		}
		else
		{
			if (kk + 1 <= k)
			{
				++kk;
			}
			else
			{
				if (a.size() >= 2)
				{
					kk = 1;
					++t;
				}
				else
				{
					res = "-1";
					break;
				}
			}
		}
		lc = t->second;
		res += to_string(lc) + ' ';
		pair<int, int> h = *t; ++h.first;
		a.erase(t);
		if (h.first < 0)
			a.insert(h);
	}
	cout << res;

	return 0;
}