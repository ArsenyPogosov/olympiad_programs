//source: 
//status: coding

#include <bits/stdc++.h>
using namespace std;
#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("linear.in ");
ofstream fout("linear.out");
#define cin fin
#define cout fout
#endif
#pragma endregion

int main()
{
	int n; cin >> n;
	stack<int> p;
	vector<int> ct; ct.reserve(n / 2);
	for (int i = 0; i < n; ++i)
	{
		int x, v; cin >> x >> v;
		if (v == 1)
			p.push(x);
		else
			if (p.size())
			{
				ct.push_back(x - p.top());
				p.pop();
			}
	}
	sort(ct.begin(), ct.end());
	int m; cin >> m;
	while (m--)
	{
		int t; cin >> t; t *= 2;
		cout << n - (upper_bound(ct.begin(), ct.end(), t) - ct.begin()) * 2 << '\n';
	}

	return 0;
}