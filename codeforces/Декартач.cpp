//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/258863/problem/A
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

vector<int> p, l, r, x, y; 

int main()
{
	int n;
	cin >> n;
	y.resize(n, -1);
	p = l = r = x = y;
	for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];
	vector<int> order(n);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int a, int b) {return x[a] < x[b]; });
	stack<int> st;
	int root = -1;
	for (auto& i : order)
	{
		while (!st.empty())
		{
			int v = st.top();
			if (y[v] < y[i])
			{
				p[i] = v;
				l[i] = r[v];
				if (r[v] >= 0) p[r[v]] = i;
				r[v] = i;
				break;
			}
			st.pop();
		}
		if (st.empty()) 
		{ 
			if (root >= 0) p[root] = i; 
			l[i] = root; 
			root = i; 
		}
		st.push(i);
	}
	cout << "YES\n";
	for (int i = 0; i < n; ++i) cout << p[i] + 1 << ' ' << l[i] + 1 << ' ' << r[i] + 1 << '\n';

	return 0;
}