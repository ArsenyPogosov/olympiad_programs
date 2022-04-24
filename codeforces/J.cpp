//source: http://neerc.ifmo.ru/school/io/archive/20191005/problems-20191005.pdf
//status: solved

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
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

int n;
vector<int> a, b;

vector<list<int>> solve(int l, int r, bool rev = false)
{
	if (l == r) return { {b[l]} };

	int m = (l + r) / 2;
	vector<list<int>> res;
	vector<list<int>> res1 = solve(l, m, true), res2 = solve(m + 1, r, false);
	if (res1.size() < res2.size()) swap(res1, res2);
	res.resize(res1.size() + 1);
	for (int i = 0; i < res2.size(); ++i)
	{
		res[i] = res1[i];
		res[i].merge(res2[i]);
	}
	for (int i = res2.size(); i < res1.size(); ++i) res[i] = res1[i];
	if (!rev)
	{
		for (int i = l; i <= m; ++i)
			res[res.size() - 1].push_back(b[i]);
	}
	if (rev)
	{
		for (int i = m + 1; i <= r; ++i)
			res[res.size() - 1].push_back(b[i]);
	}
	

	return res;
}

int main()
{
	cin >> n;
	a.resize(n);
	b.resize(n);
	for (auto& i : a) cin >> i;
	for (auto& i : b) cin >> i;
	auto res = solve(0, n - 1);
	cout << res.size() << '\n';
	for (auto& i : res)
	{
		cout << i.size() << ' ';
		for (auto& j : i) cout << j << ' ';
		cout << '\n';
	}

	return 0;
}