#include <iostream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

vector<long long> tree, add, a;

void build(long long v, long long l, long long r)
{
	tree[v] = a[l];
	if (l != r)
	{
		long long m = (l + r) / 2;
		build(v * 2 + 1, l, m);
		build(v * 2 + 2, m + 1, r);
	}
}

void fix(long long v, long long l, long long r)
{
	add[v * 2 + 1] += add[v];
	add[v * 2 + 2] += add[v];
	tree[v * 2 + 1] += add[v];
	tree[v * 2 + 2] += add[v];
	add[v] = 0;
}

long long Query(long long v, long long l, long long r, long long a)
{
	if (r < a || a < l)
		return -1;
	if (l == a)
		return tree[v];
	fix(v, l, r);
	long long m = (l + r) / 2;
	long long ans = Query(v * 2 + 1, l, m, a);
	if (ans != -1)
		return ans;
	return Query(v * 2 + 2, m + 1, r, a);
}

void Add(long long v, long long l, long long r, long long a, long long b, long long toAdd)
{
	if (a <= l && r <= b)
	{
		add[v] += toAdd;
		tree[v] += toAdd;
		return;
	}
	if (b < l || r < a)
		return;

	long long m = (l + r) / 2;
	fix(v, l, r);
	Add(v * 2 + 1, l, m, a, b, toAdd);
	Add(v * 2 + 2, m + 1, r, a, b, toAdd);
	tree[v] = tree[v * 2 + 1];
}

int main()
{
	long long n;
	cin >> n;
	a.resize(n);
	for (auto&i : a)
		cin >> i;
	tree.resize(n * 4 + 2);
	add.resize(n * 4 + 2);
	build(0, 0, n - 1);
	long long k;
	cin >> k;
	for (long long i = 0; i < k; ++i)
	{
		char h;
		cin >> h;
		if (h == 'g')
		{
			long long a;
			cin >> a;
			cout << Query(0, 0, n - 1, a - 1) << '\n';
		}
		else
		{
			long long a, b, toAdd;
			cin >> a >> b >> toAdd;
			Add(0, 0, n - 1, a - 1, b - 1, toAdd);
		}
	}

	return 0;
}