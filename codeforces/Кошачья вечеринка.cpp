//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/258385/standings/groupmates/true
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

set<pair<int, int>> l;

bool check()
{
	if (l.size() == 1) return true;
	if ((--l.end())->first - (l.begin()->first) != 1) return false;
	if ((--l.end())->first == (--(--l.end()))->first) return false;
	return true;
}

bool check2()
{
	if (l.size() == 1) return true;
	if (l.begin()->first != 1) return false;
	if ((++l.begin())->first != (--l.end())->first) return false;
	return true;
}

int main()
{
	int n;
	cin >> n;
	vector<int> u(n);
	for (auto& i : u) cin >> i;

	int m = 100001;
	vector<int> c(m);
	for (auto& i : u) ++c[i];
	for (int i = 0; i < m; ++i)
		if (c[i] != 0) l.insert({ c[i], i });
	int i = n - 1;
	while ((!check())&&(!check2()))
	{
		l.erase({ c[u[i]], u[i] });
		--c[u[i]];
		if (c[u[i]] > 0)
			l.insert({ c[u[i]], u[i] });
		--i;
	}
	cout << i + 1;

	return 0;
}