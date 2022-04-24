//source: http://neerc.ifmo.ru/school/sirius-2019/problems/20191111.pdf
//status: coding

#include <bits/stdc++.h>
using namespace std;
// f_io
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
	int n, m, k; cin >> n >> m >> k;
	vector<list<int>> perls(k);
	for (int i = 0; i < n; ++i)
	{
		int h; cin >> h; perls[h - 1].push_back(i);
	}
	set<pair<int, int>> tp;
	list<vector<int>> Ans;
	while (true)
	{
		if (tp.size() == 0)
		{
			int flag = false;
			for (int i = 0; i < k; ++i)
			{
				if (perls[i].size() == 0)
				{
					flag = true; break;
				}
				else
				{
					tp.insert({ perls[i].front(), i });
					perls[i].pop_front();
				}
			}
			if (flag) break;
		}
		if ((--tp.end())->first - tp.begin()->first <= m)
		{
			vector<int> toadd(k);
			for (auto& i : tp)
				toadd[i.second] = i.first;
			tp.clear();
			Ans.push_back(toadd);
		}
		else
		{
			int it = tp.begin()->second;
			tp.erase(tp.begin());

			if (perls[it].size() == 0) break;
			tp.insert({ perls[it].front(), it });
			perls[it].pop_front();
		}
	}
	cout << Ans.size() << '\n';
	for (auto& i : Ans)
	{
		for (auto& j : i)
			cout << j + 1 << ' ';
		cout << '\n';
	}

	return 0;
}