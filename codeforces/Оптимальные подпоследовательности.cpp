//source: https://codeforces.com/contest/1262/problem/D1
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

int main()
{
	int n, m; cin >> n;
	vector<int> a(n);
	for (auto& i : a) cin >> i;
	vector<int> order(n);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int A, int B) { return a[A] > a[B]; });
	cin >> m;
	vector<pair<int, int>> q(m);
	for (auto&i: q)
	{
		cin >> i.first >> i.second;
	}
	sort(q.begin(), q.end());
	int ws = 0;
	for (auto& i : q)
	{
		sort(order.f)
	}

	return 0;
}