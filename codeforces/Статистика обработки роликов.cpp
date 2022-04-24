//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/258385/problems
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
	long long n, k;
	cin >> n >> k;
	vector<pair<long long, long long>> v(n);
	for (auto& i : v) cin >> i.first >> i.second;
	multiset<long long> tend;
	for (auto& i : v)
	{
		while ((!tend.empty()) && *tend.begin() <= i.first) tend.erase(tend.begin());
		long long ans = i.first + i.second;
		if (tend.size() == k)
		{
			ans += *tend.begin() - i.first;
			tend.erase(tend.begin());
		}
		tend.insert(ans);
		cout << ans << '\n';
	}

	return 0;
}