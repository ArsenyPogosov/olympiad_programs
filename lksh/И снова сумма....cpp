#include <iostream>
#include <ctime>
#include <random>
//#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
#include <string>
using namespace std;

const int INF = 1000000000;

struct Node
{
	long long x;
	long long y;
	long long sum;
	Node *left;
	Node *right;

	Node(long long _x, long long _y)
	{
		x = _x;
		y = _y;
		sum = x;
		left = right = nullptr;
	}
};
typedef Node* tree;

long long sum(tree t)
{
	if (!t)
		return 0;
	return t->sum;
}

void update(tree t)
{
	if (!t)
		return;

	t->sum = sum(t->left) + sum(t->right) + t->x;
}

pair<tree, tree> split(tree t, long long key)
{
	if (!t)
		return{ nullptr, nullptr };

	if (t->x <= key)
	{
		auto res = split(t->right, key);
		t->right = res.first;
		update(t);
		return{ t, res.second };
	}

	auto res = split(t->left, key);
	t->left = res.second;
	update(t);
	return{ res.first, t };
}

tree merge(tree t1, tree t2)
{
	if (!t1)
		return t2;
	if (!t2)
		return t1;

	if (t1->y > t2->y)
	{
		t1->right = merge(t1->right, t2);
		update(t1);
		return t1;
	}
	t2->left = merge(t1, t2->left);
	update(t2);
	return t2;
}

bool find(tree t, long long key)
{
	if (!t)
		return false;
	if (t->x == key)
		return true;
	if (t->x < key)
		return find(t->right, key);

	return find(t->left, key);
}

tree insert(tree t, long long x, long long y = rand())
{
	if (find(t, x))
		return t;

	tree elem = new Node(x, y);
	auto res = split(t, x);
	return merge(merge(res.first, elem), res.second);
}

long long sum(tree t, long long l, long long r)
{
	auto t1t23 = split(t, l - 1);
	auto t2t3 = split(t1t23.second, r);
	long long res = sum(t2t3.first);
	t1t23.second = merge(t2t3.first, t2t3.second);
	merge(t1t23.first, t1t23.second);
	return res;
}

int main()
{
	srand(time(0) + 35418);
	tree t = nullptr;
	long long n;
	cin >> n;
	long long y = 0;
	for (long long i = 0; i < n; ++i)
	{
		char h;
		cin >> h;
		if (h == '+')
		{
			long long x;
			cin >> x;
			t = insert(t, (x + y) % INF);
			y = 0;
		}
		if (h == '?')
		{
			long long a, b;
			cin >> a >> b;
			cout << (y = sum(t, a, b)) << '\n';
		}
	}

	return 0;
}