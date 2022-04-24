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
	vector<long long> sum(n);
	long long m; cin >> m;
	for (long long i = 0; i < m; ++i)
	{
		long long a, b, s; cin >> a >> b >> s; --a; --b;
		sum[a] -= s; sum[b] += s;
	}
	queue<pair<long long, long long>> b, g;
	for (long long i = 0; i < n; ++i)
	{
		if (sum[i] < 0)
			b.push({ i, sum[i] });
		if (sum[i] > 0)
			g.push({ i, sum[i] });
	}
	vector<vector<long long>> res;
	while (!b.empty())
	{
		long long s = min(-b.front().second, g.front().second);
		res.push_back({ b.front().first, g.front().first, s });
		b.front().second += s;
		g.front().second -= s;
		if (b.front().second == 0) b.pop();
		if (g.front().second == 0) g.pop();
	}
	cout << res.size() << '\n';
	for (auto& i : res)
		cout << i[0] + 1 << ' ' << i[1] + 1 << ' ' << i[2] << '\n';

	return 0;
}