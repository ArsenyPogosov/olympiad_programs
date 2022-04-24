//source: 
//status: coding

#include <bits/stdc++.h>
using namespace std;
#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif
#pragma endregion

struct Node
{
	int lval, add, nval;
	bool ch;

	Node() : lval(0), add(0), ch(false) {};
	Node(int x) : lval(x), add(0), ch(false) {};
};

int n;
vector<Node> tree;

void Push(int v)
{
	if (tree[v].ch)
	{
		tree[v * 2 + 1].lval = tree[v].nval;
		tree[v * 2 + 2].lval = tree[v].nval;
		tree[v * 2 + 1].ch = tree[v * 2 + 2].ch = true;
		tree[v * 2 + 1].nval = tree[v * 2 + 2].nval = tree[v].nval;
		tree[v * 2 + 1].add = tree[v * 2 + 2].add = 0;
		tree[v].ch = false;
	}
	tree[v * 2 + 1].add += tree[v].add;
	tree[v * 2 + 2].add += tree[v].add;
	tree[v * 2 + 1].lval += tree[v].add;
	tree[v * 2 + 2].lval += tree[v].add;
	tree[v].add = 0;
}

int Query(int v, int l, int r, int ind) //!
{
	if (l > ind || r < ind) return 0;
	if (l == ind && r == ind) return tree[v].lval;

	int m = (l + r) / 2;
	Push(v);
	return Query(v * 2 + 1, l, m, ind) +
		Query(v * 2 + 2, m + 1, r, ind);
}

void Change(int v, int l, int r, int L, int R, int val)
{
	if (R < l || r < L) return;
	if (L <= l && r <= R)
	{
		tree[v].ch = true;
		tree[v].add = 0;
		tree[v].nval = val;
		tree[v].lval = val;
		return;
	}

	int m = (l + r) / 2;
	Push(v);
	Change(v * 2 + 1, l, m, L, R, val);
	Change(v * 2 + 2, m + 1, r, L, R, val);

}

void Add(int v, int l, int r, int L, int R, int add)
{
	if (R < l || r < L) return;
	if (L <= l && r <= R)
	{
		tree[v].lval += add;
		tree[v].add += add;
		return;
	}

	int m = (l + r) / 2;
	Push(v);
	Add(v * 2 + 1, l, m, L, R, add);
	Add(v * 2 + 2, m + 1, r, L, R, add);
}

ostringstream Sol1(istringstream &cin)
{
	ostringstream cout;
	cin >> n;
	tree.assign(n * 4 + 228, 0);

	int m;
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int h;
		cin >> h;
		if (h == 1)
		{
			int ind;
			cin >> ind;
			--ind;
			cout << Query(0, 0, n - 1, ind) << "\n";
		}
		if (h == 2)
		{
			int l, r, nval;
			cin >> l >> r >> nval;
			--l; --r;
			Change(0, 0, n - 1, l, r, nval);
		}
		if (h == 3)
		{
			int l, r, add;
			cin >> l >> r >> add;
			--l; --r;
			Add(0, 0, n - 1, l, r, add);
		}
	}

	return cout;
}

ostringstream Sol2(istringstream &cin)
{ 
	ostringstream cout;
	int n; cin >> n;
	vector<int> mass(n);
	int m; cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int reg; cin >> reg;
		if (reg == 1)
		{
			int ind; cin >> ind;
			cout << mass[ind - 1] << '\n';
		}
		if (reg == 2)
		{
			int l, r, val; cin >> l >> r >> val; --l; --r;
			for (int j = l; j <= r; ++j)
				mass[j] = val;
		}
		if (reg == 3)
		{
			int l, r, add; cin >> l >> r >> add; --l; --r;
			for (int j = l; j <= r; ++j)
				mass[j] += add;
		}
	}

	return cout;
}

istringstream Gen()
{
	ostringstream test;
	int n = rand() % 1000 + 1;
	int m = rand() % 1000 + 1;
	test << n << '\n' << m << '\n';
	for (int i = 0; i < m; ++i)
	{
		int reg = rand() % 3 + 1;
		test << reg << ' ';
		if (reg == 1)
		{
			test << rand() % n + 1 << '\n';
		}
		if (reg == 2)
		{
			int l = rand() % n + 1, r = rand() % n + 1;
			if (l > r) swap(l, r);
			test << l << ' ' << r << ' ' << rand() % 2001 - 1000 << '\n';
		}
		if (reg == 3)
		{
			int l = rand() % n + 1, r = rand() % n + 1;
			if (l > r) swap(l, r);
			test << l << ' ' << r << ' ' << rand() % 2001 - 1000 << '\n';
		}
	}

	return istringstream(test.str());
}

bool Check(ostringstream cout1, ostringstream cout2)
{
	return cout1.str() == cout2.str();
}

int main()
{
	/*int count = 0;
	while (true)
	{
		++count;
		istringstream test1 = Gen(), test2 = istringstream(test1.str());
		if (!Check(Sol1(test1), Sol2(test2)))
		{
			cout << test1.str();
			break;
		}
		if (count % 10 == 0) cout << char(rand());
	}*/
	for (int i = 0; i < 30; ++i) cout << char(rand());

	return 0;
}