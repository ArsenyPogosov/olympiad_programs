//source: https://drive.google.com/file/d/1W9UCJV9ZvVCEOnb0MydlVIah0qfC6NUH/view
//status: coding

#include <bits/stdc++.h>
using namespace std;
#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("maxincycle.in");
ofstream fout("maxincycle.out");
#define cin fin
#define cout fout
#endif
#pragma endregion

vector<int> dsu, r;

int get(int x)
{
	return (dsu[x] == -1 ? x : dsu[x] = get(dsu[x]));
}

bool con(int x, int y)
{
	return get(x) == get(y);
}

void unite(int x, int y)
{
	x = get(x); y = get(y);
	if (x == y) return;
	if (r[x] > r[y]) swap(x, y);
	dsu[x] = y;
	if (r[x] == r[y]) ++r[y];
}

void buildDSU(int n)
{
	dsu.resize(n, -1); r.resize(n);
}

int main()
{
	int n, m; cin >> n >> m;
	buildDSU(n);
	list<int> res;
	for (int i = 0; i < m; ++i)
	{
		int a, b; cin >> a >> b; --a; --b;
		if (!con(a, b))
		{
			res.push_back(i);
			unite(a, b);
		}
	}
	cout << res.size() << '\n';
	for (auto& i : res) cout << i + 1 << ' ';

	return 0;
}