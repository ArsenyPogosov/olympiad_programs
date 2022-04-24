//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/260618/problem/D
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

struct node
{
	node *c[2];
	int size, Xor;
	bool term;
	node(bool t = false) { c[0] = c[1] = nullptr; size = t; Xor = 0; term = t; }
	node* move(int x)
	{
		if (!c[x % 2]) c[x % 2] = new node();
		return c[x % 2];
	}
	list<int> all()
	{
		list<int> res;
		if (c[0])
			res = this->move(0)->all();
	}
};

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<int> mass(n);
	int xo = 0;
	for (int f = 0; f < m; ++f)
	{
		string s;
		cin >> s;
		if (s == "xor")
		{
			int x; cin >> x; xo ^= x;
		}
		if (s == "and")
		{
			if (xo != 0)
			{
				for (auto& i : mass)
					i ^= xo;
				xo = 0;
			}
			int x; cin >> x; an &= x;
		}
		if (s == "?")
		{
			int l, r; cin >> l >> r;
			int count = 0;
			for (auto& i : mass)
				if (l <= i && i <= r)
					++count;
			cout << count << '\n';
		}
	}

	return 0;
}