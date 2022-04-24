#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const int N = 18 * 2;
const __int128 P = __int128(1e18)*__int128(1e18);

struct bigint
{
	vector<__int128> body;
	bigint() : body(0) {}
	bigint(__int128 x) : body((x ? 1 : 0), x) {}

	bigint(string& s)
	{
		body.assign(0, 0);
		for (int i = s.size() - 1; i >= 0; i -= N)
		{
			string h = s.substr(max(0, i - N + 1), min(N, i + 1)); h = string(N - h.size(), '0') + h;
			body.push_back(__int128(atoll(h.substr(0, N / 2).c_str()))*__int128(1e18) + __int128(atoll(h.substr(N / 2, N / 2).c_str())));
		}
	}

	bigint operator+(bigint& b)
	{
		bigint res; res.body.resize(max(body.size(), b.body.size()) + 1);
		for (int i = 0, ch = 0; i < res.body.size(); ++i)
		{
			__int128 x = 0; if (i < body.size()) x = body[i];
			__int128 y = 0; if (i < b.body.size()) y = b.body[i];
			__int128 z = x + y + ch; ch = 0;
			if (z > P) z -= P, ch = 1;
			res.body[i] = z;
		}
		while (res.body.size() && !res.body.back()) res.body.pop_back();

		return res;
	}

	bigint operator-(bigint& b)
	{
		bigint res; res.body.resize(max(body.size(), b.body.size()) + 1);
		for (int i = 0, ch = 0; i < res.body.size(); ++i)
		{
			__int128 x = 0; if (i < body.size()) x = body[i];
			__int128 y = 0; if (i < b.body.size()) y = b.body[i];
			__int128 z = x - y - ch; ch = 0;
			if (z < 0) z += P, ch = 1;
			res.body[i] = z;
		}
		while (res.body.size() && !res.body.back()) res.body.pop_back();

		return res;
	}

	bool operator<(bigint& b)
	{
		if (body.size() != b.body.size()) return (body.size() < b.body.size());

		for (int i = body.size() - 1; i >= 0; --i)
			if (body[i] != b.body[i])
				return body[i] < b.body[i];
		return false;
	}
};

bigint zero = bigint(0);
bigint one = bigint(1);

struct node
{
	bigint x, add;
	int id, y;
	node* l, * r;
	node(bigint x = zero, int id = 0) : x(x), id(id), y(rand()* RAND_MAX + rand()), add(zero), l(nullptr), r(nullptr) {}
};
typedef node* treap;

void add(treap t, bigint val)
{
	if (!t) return;
	t->x = t->x + val;
	t->add = t->add + val;
}

void push(treap t)
{
	if (!t) return;
	if (t->l) add(t->l, t->add);
	if (t->r) add(t->r, t->add);
	t->add = zero;
}

void split(treap t, bigint k, treap& t1, treap& t2)
{
	if (!t)
	{
		t1 = t2 = nullptr;
		return;
	}

	push(t);
	if (t->x < k)
	{
		split(t->r, k, t->r, t2);
		t1 = t;
	}
	else
	{
		split(t->l, k, t1, t->l);
		t2 = t;
	}
}

treap merge(treap t1, treap t2)
{
	if (!t1) return t2;
	if (!t2) return t1;

	if (t1->y < t2->y)
	{
		push(t1);
		t1->r = merge(t1->r, t2);
		return t1;
	}
	else
	{
		push(t2);
		t2->l = merge(t1, t2->l);
		return t2;
	}
}

void insert(treap& t, bigint x, int id)
{
	treap t1, t2; split(t, x, t1, t2);
	add(t2, x);
	t = merge(t1, merge(new node(x + x - one, id), t2));
}

vector<int> path;

void dfs(treap t)
{
	if (!t) return;

	if (t->l) dfs(t->l);
	path.push_back(t->id);
	if (t->r) dfs(t->r);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	treap t = nullptr;

	bigint was = zero;
	for (int i = 0; i < n; ++i)
	{
		string s; cin >> s;
		insert(t, bigint(s) - was, i);
		was = bigint(s);
	}

	dfs(t);
	vector<int> res(n);
	for (int i = 0; i < n; ++i)
		res[path[i]] = i;
	for (auto& i : res)
		cout << i + 1 << ' ';
	cout << '\n';

	return 0;
}