#include <iostream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

const long long NO_CHANGE = 100001;
const long long SIZE1 = 400002;
const long long SIZE2 = 100000;
const long long POW1 = 2;
const long long POW2 = 3;
const long long MOD1 = 12345;
const long long MOD2 = 23456;
const long long INF = 100001;

vector<long long> minTree(SIZE1), maxTree(SIZE1), change(SIZE1, NO_CHANGE);

long long ModPow(long long n, long long pow, long long p)
{
	n %= p;
	if (pow == 1)
		return n;
	return ModPow(n, pow - 1, p) * n % p;
}

void build(long long v, long long l, long long r)
{
	if (l == r)
	{
		minTree[v] = maxTree[v] = ModPow(l, POW1, MOD1) + ModPow(l, POW2, MOD2);
		return;
	}

	long long m = (l + r) / 2;
	build(v * 2 + 1, l, m);
	build(v * 2 + 2, m + 1, r);
	minTree[v] = min(minTree[v * 2 + 1], minTree[v * 2 + 2]);
	maxTree[v] = max(maxTree[v * 2 + 1], maxTree[v * 2 + 2]);
}

void fix(long long v, long long l, long long r)
{
	if (change[v] == NO_CHANGE)
		return;

	change[v * 2 + 1] = change[v * 2 + 2] = change[v];
	minTree[v * 2 + 1] = minTree[v * 2 + 2] = change[v];
	maxTree[v * 2 + 1] = maxTree[v * 2 + 2] = change[v];
	change[v] = NO_CHANGE;
}

long long MaxInTree(long long v, long long l, long long r, long long a, long long b)
{
	if (a <= l && r <= b)
		return maxTree[v];
	if (b < l || r < a)
		return -INF;

	fix(v, l, r);
	long long m = (l + r) / 2;
	return max(MaxInTree(v * 2 + 1, l, m, a, b), MaxInTree(v * 2 + 2, m + 1, r, a, b));
}

long long MinInTree(long long v, long long l, long long r, long long a, long long b)
{
	if (a <= l && r <= b)
		return minTree[v];
	if (b < l || r < a)
		return INF;

	fix(v, l, r);
	long long m = (l + r) / 2;
	return min(MinInTree(v * 2 + 1, l, m, a, b), MinInTree(v * 2 + 2, m + 1, r, a, b));
}

long long Query(long long a, long long b)
{
	return MaxInTree(0, 1, SIZE2, a, b) - MinInTree(0, 1, SIZE2, a, b);
}

void Change(long long v, long long l, long long r, long long a, long long b, long long nw)
{
	if (a <= l && r <= b)
	{
		change[v] = nw;
		minTree[v] = change[v];
		maxTree[v] = change[v];
		return;
	}
	if (b < l || r < a)
		return;

	long long m = (l + r) / 2;
	fix(v, l, r);
	Change(v * 2 + 1, l, m, a, b, nw);
	Change(v * 2 + 2, m + 1, r, a, b, nw);
	minTree[v] = min(minTree[v * 2 + 1], minTree[v * 2 + 2]);
	maxTree[v] = max(maxTree[v * 2 + 1], maxTree[v * 2 + 2]);
}

int main()
{
	build(0, 1, SIZE2);
	long long k;
	cin >> k;
	for (long long i = 0; i < k; ++i)
	{
		long long a, b;
		cin >> a >> b;
		if (a > 0)
			cout << Query(a, b) << '\n';
		else
			Change(0, 1, SIZE2, -a, -a, b);
	}

	return 0;
}