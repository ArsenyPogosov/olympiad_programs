#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long p = 1e9 + 7;
const long long div2 = (p + 1) / 2;

vector<int> pw2, vcofsum, vcoflsum, cntcofsum, cntcoflsum;

struct node
{
	node* l, * r;
	int x, sum, lsum, cnt, g;
	node(int x = 0): x(x), sum(x), lsum(x), cnt(1), g(0), l(nullptr), r(nullptr) { }
};
typedef node* tree;

void grow(tree t, int g)
{
	t->sum = (t->sum + t->lsum * 1ll * vcofsum[g] % p + t->cnt * 1ll * cntcofsum[g] % p) % p;
	t->lsum = (t->lsum * 1ll * vcoflsum[g] % p + t->cnt * 1ll * cntcoflsum[g] % p) % p;
	t->cnt = t->cnt * 1ll * pw2[g] % p;
	t->g += g;
}

void push(tree t)
{
	if (!t->g) return;

	if (!t->l)
	{
		t->l = new node(t->x * 2);
		t->r = new node(t->x * 2 + 1);
		--t->g;
	}
	if (!t->g) return;
	grow(t->l, t->g);
	grow(t->r, t->g);
	t->g = 0;
}

tree t = new node(1);

void Grow(int n)
{
	vector<char> path;
	while (n > 1)
	{
		path.push_back(n % 2);
		n /= 2;
	}
	tree v = t;
	vector<tree> tpath;
	for (int i = path.size() - 1; i >= 0; --i)
	{
		tpath.push_back(v);
		push(v);
		v = (path[i] ? v->r : v->l);
	}
	long long sumadd = -v->sum, lsumadd = -v->lsum, cntadd = -v->cnt;
	grow(v, 1);
	sumadd += v->sum;
	lsumadd += v->lsum;
	cntadd += v->cnt;
	for (int i = tpath.size() - 1; i >= 0; --i)
	{
		tpath[i]->sum = ((tpath[i]->sum + sumadd) % p + p) % p;
		tpath[i]->lsum = ((tpath[i]->lsum + lsumadd) % p + p) % p;
		tpath[i]->cnt = ((tpath[i]->cnt + cntadd) % p + p) % p;
	}
}

long long Sum(int n)
{
	vector<char> path;
	while (n > 1)
	{
		path.push_back(n % 2);
		n /= 2;
	}
	tree v = t;
	for (int i = path.size() - 1; i >= 0; --i)
	{
		push(v);
		v = (path[i] ? v->r : v->l);
	}

	return v->sum;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int maxg = 2 * 1e5 + 2;
	pw2.resize(maxg);
	pw2[0] = 1;
	for (int i = 1; i < maxg; ++i)
		pw2[i] = pw2[i - 1] * 1ll * 2 % p;

	vcoflsum.resize(maxg);
	for (long long i = 1; i < maxg; ++i)
	{
		vcoflsum[i] = pw2[i] * 1ll * pw2[i] % p;
	}
	vcofsum.resize(maxg);
	for (int i = 1; i < maxg; ++i)
		vcofsum[i] = (vcofsum[i - 1] + vcoflsum[i]) % p;

	cntcoflsum.resize(maxg);
	for (long long i = 1; i < maxg; ++i)
		cntcoflsum[i] = pw2[i] * 1ll * (pw2[i] - 1) % p * div2 % p;
	cntcofsum.resize(maxg);
	for (int i = 1; i < maxg; ++i)
		cntcofsum[i] = (cntcofsum[i - 1] + cntcoflsum[i]) % p;

	int n; cin >> n;
	for (int ttt = 0; ttt < n; ++ttt)
	{
		string s; int x;
		cin >> s >> x;
		if (s == "Grow")
			Grow(x);
		if (s == "Sum")
			cout << Sum(x) << '\n';
	}

	return 0;
}