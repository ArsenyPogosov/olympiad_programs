#include<bits/stdc++.h>
using namespace std;

const int MAX = 512 * 1024 * 1024 - 10000000;
int t = 0;
char mem[MAX];

void* operator new(size_t sz)
{
	t += sz;

	if (t >= MAX)
		cout << '!';

	return &mem[t - sz];
}

void operator delete(void* t)
{

}

int n = 31;

struct node
{
	int sz;
	vector<char> change;
	vector<int> cnt;
	node *l, *r;
	node(int d)
	{
		sz = 0;
		change = vector<char>(max(0, d - 1), 0);
		cnt.resize(d);
		l = r = nullptr;
	}
};
typedef node* bor;

int sz(bor t)
{
	return (t ? t->sz : 0);
}

long long sum(bor t, vector<char> ch)
{
	if (!t) return 0;

	long long res = 0;
	for (int i = 0; i < t->cnt.size(); ++i)
		if (!ch[i])
			res += (t->cnt[i]) * (1ll << i);
		else
			res += (t->sz - t->cnt[i]) * (1ll << i);

	return res;
}

bor add(bor t, vector<char> ch)
{
	bor nt = new node(0);
	if (t)
		*nt = *t;
	else
		nt = nullptr;

	if (!t) return nt;

	++nt->sz;
	for (int i = 0; i < ch.size(); ++i)
		nt->cnt[i] += ch[i];

	if (ch.empty()) return nt;

	if (ch.back())
	{
		ch.pop_back();
		if (!nt->r)
			nt->r = new node(nt->cnt.size() - 1);
		nt->r = add(nt->r, ch);
	}
	else
	{
		ch.pop_back();
		if (!nt->l)
			nt->l = new node(nt->cnt.size() - 1);
		nt->l = add(nt->l, ch);
	}

	return nt;
}

long long sumk(bor t1, bor t2, vector<char> ch, int k)
{
	if (ch.empty()) ch = vector<char>(1, 0);
	if (sz(t2)-sz(t1) == 0) return 0;
	if (!k) return 0;

	if (sz(t2)-sz(t1) == k)
		return sum(t2, ch) - sum(t1, ch);

	bool swp = ch.back(); ch.pop_back();
	if (swp)
	{
		if (t1)
			swap(t1->l, t1->r);
		if (t2)
			swap(t2->l, t2->r);
	}

	int r = min(k, sz(t2->r)- (t1 ? sz(t1->r) : 0)), l = k - r;
	long long res = 0;
	res += r * (1ll << (t2->cnt.size() - 1));
	res += sumk((t1 ? t1->l : nullptr), t2->l, ch, l);
	res += sumk((t1 ? t1->r : nullptr), t2->r, ch, r);

	if (swp)
	{
		if (t1)
			swap(t1->l, t1->r);
		if (t2)
			swap(t2->l, t2->r);
	}

	return res;
}

vector<char> convert(int x)
{
	vector<char> res(n);
	for (auto& i : res)
		i = (x & 1), x >>= 1;

	return res;
}

int main()
{
	double t = clock();

	int q; 
	//q = 1e5;
	cin >> q;
	vector<bor> T{ new node(n) };
	while (q--)
	{
		char h;
		//h = (rand() % 2 ? '+' : '?');
		cin >> h;
		if (h == '+')
		{
			int x;
			//x = rand() % int(1e9);
			cin >> x;

			T.push_back(add(T.back(), convert(x)));
		}
		if (h == '?')
		{
			int l, r, x, k; 
			//x = rand() % int(1e9);
			//l = rand() % (T.size() - 1); r = rand() % (T.size() - 1);
			//if (l > r) swap(l, r);
			//k = rand() % (r - l + 1);
			cin >> l >> r >> x >> k;
			--l; --r;

			cout << sumk(T[l], T[r + 1], convert(x), k) << '\n';
		}
	}

	//cout << (clock() - t) / CLOCKS_PER_SEC << '\n';

	return 0;
}