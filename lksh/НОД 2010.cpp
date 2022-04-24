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

struct Node
{
	int x;
	int y;
	int gcd;
	int count;
	Node *left;
	Node *right;

	Node(int _x, int _y)
	{
		x = _x;
		y = _y;
		count = 1;
		gcd = x;
		left = right = nullptr;
	}
};
typedef Node* tree;

int GCD(tree t)
{
	if (!t)
		return 1;
	return t->gcd;
}

int GCD(int a, int b)
{
	if (a == 0)
		return b;
	return GCD(b % a, a);
}

void update(tree t)
{
	if (!t)
		return;
	int g1 = GCD(t->left), g2 = GCD(t->right);
	if (t->left == nullptr && t->right == nullptr)
	{
		t->gcd = t->x;
		return;
	}
	if (t->left == nullptr)
	{
		t->gcd = GCD(t->x, g2);
		return;
	}
	if (t->right == nullptr)
	{
		t->gcd = GCD(t->x, g1);
		return;
	}
	t->gcd = GCD(t->x, GCD(g1, g2));
}

pair<tree, tree> split(tree t, int key)
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

int GCD(tree& t, int l, int r)
{
	auto t1t23 = split(t, l - 1);
	auto t2t3 = split(t1t23.second, r);
	int res = GCD(t2t3.first);
	t = merge(t1t23.first, merge(t2t3.first, t2t3.second));
	return res;
}

tree insert(tree t, int x, int y = rand())
{
	auto t1t23 = split(t, x - 1);
	auto t2t3 = split(t1t23.second, x);
	if (t2t3.first)
		++t2t3.first->count;
	else
		t2t3.first = new Node(x, y);
	t = merge(t1t23.first, merge(t2t3.first, t2t3.second));
	return t;
}

tree erase(tree t, int x)
{
	auto t1t23 = split(t, x - 1);
	auto t2t3 = split(t1t23.second, x);
	--t2t3.first->count;
	if (t2t3.first->count == 0)
		t2t3.first = nullptr;
	t = merge(t1t23.first, merge(t2t3.first, t2t3.second));
	return t;
}

int main()
{
	srand(time(0) + 35418);
	tree t = nullptr;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		char r;
		cin >> r;
		if (r == '+')
		{
			int h;
			cin >> h;
			t = insert(t, h);
		}
		if (r == '-')
		{
			int h;
			cin >> h;
			t = erase(t, h);
		}
		if (r == '?')
		{
			int a, b;
			cin >> a >> b;
			cout << GCD(t, a, b) << '\n';
		}
	}

	return 0;
}