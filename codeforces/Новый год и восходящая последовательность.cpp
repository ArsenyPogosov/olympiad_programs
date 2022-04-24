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
	long long n; cin >> n;
	vector<vector<long long>> s(n);
	for (auto& i : s)
	{
		long long l; cin >> l;
		i.resize(l);
		for (auto& j : i)
			cin >> j;
	}
	long long cr = 0;
	vector<long long> b, e;
	for (auto& i : s)
	{
		bool flag = false;
		for (long long j = 0; j < i.size() - 1; ++j)
			if (i[j] < i[j + 1])
			{
				flag = true;
				break;
			}
		if (flag)
		{
			++cr;
			continue;
		}
		b.push_back(i[0]);
		e.push_back(i[i.size() - 1]);
	}
	sort(b.begin(), b.end());
	long long res = cr * n * 2 - cr * cr;
	for (auto& i : e)
	{
		res += (b.size() - (upper_bound(b.begin(), b.end(), i) - b.begin()));
	}
	cout << res;
	return 0;
}