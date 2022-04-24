//source: 
//status: coding

#include <bits/stdc++.h>
#include <unordered_map>
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

struct point
{
	long long x;
	long long y;
	point() { x = y = 0; }
	point(long long _x, long long _y) { x = _x; y = _y; }
};

int main()
{
	long long n; cin >> n;
	vector<point> p(n);
	for (auto& i : p) cin >> i.x >> i.y;
	while (true)
	{
		bool ch = false, nch = false;
		for (auto& i : p)
		{
			if (i.x % 2 != 0 || i.y % 2 != 0)
			{
				nch = true;
			}
			if (i.x % 2 == 0 || i.y % 2 == 0)
			{
				ch = true;
			}
		}
		if (nch && ch) break;
		if (p[0].x % 2 == 0)
			for (auto& i : p) { i.x /= 2; i.y /= 2; }
		else
			for (auto& i : p) { i.x = (i.x + 1) / 2; i.y = (i.y + 1) / 2; }
	}

	vector<int> ans; ans.reserve(n);
	for (int i = 0; i < n; ++i)
	{
		if ((p[i].x + p[i].y) % 2 == 0)
			ans.push_back(i + 1);
	}
	if (ans.size() != 0 && ans.size() != n)
	{
		cout << ans.size() << '\n';
		for (auto& i : ans) cout << i << ' ';
		cout << '\n';
		return 0;
	}
	ans.clear(); ans.reserve(n);
	for (int i = 0; i < n; ++i)
	{
		if (p[i].x % 2 == 0)
			ans.push_back(i + 1);
	}
	cout << ans.size() << '\n';
	for (auto& i : ans) cout << i << ' ';
	cout << '\n';

	return 0;
}