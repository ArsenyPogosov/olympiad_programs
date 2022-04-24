#include <iostream>
#include <vector>
//#include <queue>
#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

vector<list<int>> g, ng;
vector<int> color, colour, gsort;
list<int> con;

void TopSort(int v)
{
	color[v] = 1;
	for (auto&i : g[v])
		if (color[i] == 0)
			TopSort(i);
	gsort.push_back(v);
}

void FormComp(int v, int c)
{
	color[v] = c;
	for (auto&i : ng[v])
		if (color[i] == -1)
			FormComp(i, c);
}

void FillCon(int v)
{
	colour[v] = 1;
	for (auto&i : g[v])
	{
		if (colour[i] == 0 && color[i] == color[v])
			FillCon(i);
		if (color[i] != color[v])
			con.push_back(color[i]);
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	g.resize(n);
	ng.resize(n);
	for (int i = 0; i < m; ++i)
	{
		int a, b;
		cin >> a >> b;
		--a;
		--b;
		g[a].push_back(b);
		ng[b].push_back(a);
	}

	color.resize(n);
	gsort.reserve(n);
	for (int i = 0; i < n; ++i)
		if (color[i] == 0)
			TopSort(i);
	reverse(gsort.begin(), gsort.end());

	color.assign(n, -1);
	int c = 0;
	for (int i = 0; i < n; ++i)
		if (color[gsort[i]] == -1)
			FormComp(gsort[i], c++);

	vector<bool> check(c, true);
	colour.resize(n, 0);
	int count = 0;
	for (int i = 0; i < n; ++i)
		if (check[color[i]])
		{
			check[color[i]] = false;
			FillCon(i);
			con.sort();
			int h = -1;
			while (!con.empty())
			{
				if (con.front() != h) // h = con.front()+++count*0
				{
					h = con.front();
					++count;
				}
				con.pop_front();
			}
		}
	cout << count;

	return 0;
}