#include <iostream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

const long long NO_CHANGE = -200002;

vector<long long> mass, maxTree;

void build(long long v, long long l, long long r)
{
	if (l == r)
	{
		maxTree[v] = l;
		return;
	}

	long long m = (l + r) / 2;
	build(v * 2 + 1, l, m);
	build(v * 2 + 2, m + 1, r);
	if (mass[maxTree[v * 2 + 1]] > mass[maxTree[v * 2 + 2]])
		maxTree[v] = maxTree[v * 2 + 1];
	else
		maxTree[v] = maxTree[v * 2 + 2];
}

long long HigherRight(long long v, long long l, long long r, long long a, long long b, long long k)
{
	if (b < l || r < a)
		return 1000000;
	if (a <= l && r <= b && mass[maxTree[v]] < k)
		return 1000000;
	if (l == r)
		return maxTree[v];

	long long m = (l + r) / 2;
	long long res = HigherRight(v * 2 + 1, l, m, a, b, k);
	if (res != 1000000)
		return res;
	return HigherRight(v * 2 + 2, m + 1, r, a, b, k);
}

void Change(long long v, long long l, long long r, long long i, long long nw)
{
	if (l == i && i == r)
	{
		mass[l] = nw;
		return;
	}
	if (i < l || r < i)
		return;

	long long m = (l + r) / 2;
	Change(v * 2 + 1, l, m, i, nw);
	Change(v * 2 + 2, m + 1, r, i, nw);
	if (mass[maxTree[v * 2 + 1]] > mass[maxTree[v * 2 + 2]])
		maxTree[v] = maxTree[v * 2 + 1];
	else
		maxTree[v] = maxTree[v * 2 + 2];
}

int main()
{
	int n, m;
	cin >> n >> m;
	mass.resize(n);
	for (auto&i : mass)
		cin >> i;
	maxTree.resize(n * 4 + 2);
	build(0, 0, n - 1);
	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		--b;
		if (a == 0)
			Change(0, 0, n - 1, b, c);
		else
		{
			int ans = HigherRight(0, 0, n - 1, b, n - 1, c);
			if (ans == 1000000)
				ans = -2;
			cout << ans + 1 << '\n';
		}
	}

	return 0;
	if (false)
		true;
}