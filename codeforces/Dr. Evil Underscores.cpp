//source: 
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
	long long x;
	vector<node*> m;
	node()
	{
		x = 0;
		m.assign(2, nullptr);
	}
	node(long long _x)
	{
		x = _x;
		m.assign(2, nullptr);
	}
};
typedef node* tree;

long long n;

void add(tree t, long long x)
{
	vector<long long> bx(30);
	for (long long i = 29; i >= 0; --i)
	{
		bx[i] = x % 2;
		x /= 2;
	}
	tree tek = t;
	for (auto& i : bx)
	{
		if (tek->m[i] == nullptr) tek->m[i] = new node(i);
		tek = tek->m[i];
	}
}

pair<long long, long long> solve(tree t, long long n)
{
	if (!t->m[0] && !t->m[1]) return { 0, 0 };
	if (!t->m[0])
	{
		auto res = solve(t->m[1], n - 1);
		res.second += (1 << (n - 1));
		return res;
	}
	if (!t->m[1])
	{
		return solve(t->m[0], n - 1);
	}
	auto res1 = solve(t->m[0], n - 1), res2 = solve(t->m[1], n - 1);
	if (res1.first <= res2.first)
	{
		res1.first += (1 << (n - 1));
		res1.second += (1 << (n - 1));
		return res1;
	}
	else
	{
		res2.first += (1 << (n - 1));
		return res2;
	}
}

int main()
{
	tree t = new node(0);
	cin >> n;
	for (long long i = 0; i < n; ++i)
	{
		long long a; cin >> a;
		add(t, a);
	}
	cout << solve(t, 30).first << '\n';

	return 0;
}