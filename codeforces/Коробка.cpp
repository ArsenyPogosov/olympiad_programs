//source: https://codeforces.com/contest/1262/problem/B
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
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int ttt; cin >> ttt;
	for (int tt = 0; tt < ttt; ++tt)
	{
		int n; cin >> n;
		vector<int> used(n);
		int pq = -1;
		vector<int> res; res.reserve(n);
		bool flag = true;
		int it = 0;
		for (int i = 0; i < n; ++i)
		{
			int q; cin >> q;
			if (pq < q)
			{
				res.push_back(q);
				used[q - 1] = true;
			}
			else
			{
				if (pq == q)
				{
					for (; it <= q; ++it)
						if (!used[it - 1])
							break;
					if (it <= q && !used[it - 1])
					{
						res.push_back(it);
						used[it - 1] = true;
					}
					else
					{
						cout << -1;
						flag = false;
						for (i = i + 1; i < n; ++i)
							cin >> q;
						break;
					}

				}
				else
				{
					cout << -1;
					flag = false;
					for (i = i + 1; i < n; ++i)
						cin >> q;
					break;
				}
			}
			pq = q;
		}
		if (flag)
			for (auto& i : res) cout << i << ' ';
		cout << '\n';
	}

	return 0;
}