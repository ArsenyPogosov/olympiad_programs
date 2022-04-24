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

int n;

struct node {
	int sum, add;
	node() : sum(0), add(0) {};
	node(int x) : sum(x), add(0) {};
};
vector<node> tree;

void build()
{
	tree.assign(n * 4 * 4 + 100, node());
}

void add(int v, int l, int r, int tadd)
{
	tree[v].sum += tadd * (r - l + 1);
	tree[v].add += tadd;
}

void push(int v, int l, int r)
{
	int m = (l + r) / 2;
	add(v * 2 + 1, l, m, tree[v].add);
	add(v * 2 + 2, m + 1, r, tree[v].add);
	tree[v].add = 0;
}

int Query(int v, int l, int r, int L, int R)
{
	if (L < r || R < l) return 0;
	if (L <= l && r <= R) return tree[v].sum;
	push(v, l, r);
	int m = (l + r) / 2;
	return Query(v * 2 + 1, l, m, L, R) + Query(v * 2 + 2, m + 1, r, L, R);
}

void Add(int v, int l, int r, int L, int R, int tadd)
{
	if (L < r || R < l) return;
	if (L <= l && r <= R) return add(v, l, r, tadd);
	int m = (l + r) / 2;
	Add(v * 2 + 1, l, m, L, R, tadd);
	Add(v * 2 + 2, m + 1, r, L, R, tadd);
}

bool checkL(vector<pair<int, int>>& A, vector<pair<int, int>>& B)
{
	vector<int> p(n);
	iota(p.begin(), p.end(), 0);
	sort(p.begin(), p.end(), [&](int x, int y) {
		return (A[x].first < A[y].first) || ((A[x].first == A[y].first) && (A[x].second > A[y].second));
		});
	set<pair<int, int>> tm;
	build();
	for (auto& i : p)
	{
		while (tm.size())
		{
			if (tm.begin()->first >= A[i].first) break;
			Add(0, 0, n * 4 + 5, B[tm.begin()->second].first, B[tm.begin()->second].second, -1);
			tm.erase(tm.begin());
		}
		if (Query(0, 0, n * 4 + 5, B[i].first, B[i].second) < tm.size())
			return false;

		tm.insert({ A[i].second, i });
		Add(0, 0, n * 4 + 5, B[i].first, B[i].second, 1);
	}
	return true;
}
bool checkR(vector<pair<int, int>>& A, vector<pair<int, int>>& B)
{
	vector<int> p(n);
	iota(p.begin(), p.end(), 0);
	sort(p.begin(), p.end(), [&](int x, int y) {
		return (B[x].second > B[y].second) || ((B[x].second == B[y].second) && (B[x].first < B[y].first));
		});
	set<pair<int, int>, greater<pair<int, int>>> tm;
	build();
	for (auto& i : p)
	{
		while (tm.size())
		{
			if (tm.begin()->first <= A[i].first) break;
			Add(0, 0, n * 4 + 5, A[tm.begin()->second].first, A[tm.begin()->second].second, -1);
			tm.erase(tm.begin());
		}
		if (Query(0, 0, n * 4 + 5, A[i].first, A[i].second) < tm.size())
			return false;

		tm.insert({ B[i].second, i });
		Add(0, 0, n * 4 + 5, A[i].first, A[i].second, 1);
	}
	return true;
}

int main()
{
	cin >> n;
	vector<pair<int, int>> A(n), B(n);
	vector<pair<int, pair<int, pair<int, int>>>> coord; coord.reserve(n * 4);
	for (int i = 0; i < n; ++i)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		coord.push_back({ a, {1, {i, 1}} });
		coord.push_back({ b, {1, {i, 2}} });
		coord.push_back({ c, {2, {i, 1}} });
		coord.push_back({ d, {2, {i, 2}} });
	}
	sort(coord.begin(), coord.end());
	int count = 0, pr = 0;
	for (auto& i : coord)
	{
		if (pr != i.first)
		{
			pr = i.first;
			++count;
		}
		if (i.second.first == 1)
			if (i.second.second.second == 1)
				A[i.second.second.first].first = count;
		if (i.second.first == 1)
			if (i.second.second.second == 2)
				A[i.second.second.first].second = count;
		if (i.second.first == 2)
			if (i.second.second.second == 1)
				B[i.second.second.first].first = count;
		if (i.second.first == 2)
			if (i.second.second.second == 2)
				B[i.second.second.first].second = count;
	}
	if (checkL(A, B) && checkL(B, A) && checkR(A, B) && checkR(B, A))
		cout << "YES\n";
	else
		cout << "NO\n";

	return 0;
}