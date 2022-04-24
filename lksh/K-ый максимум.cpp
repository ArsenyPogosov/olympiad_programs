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

struct node
{
	int x;
	int y;
	int size;
	node *left;
	node *right;

	node(int _x, int _y)
	{
		x = _x;
		y = _y;
		size = 1;
		left = right = nullptr;
	}
};
typedef node* tree;

int len(tree t)
{
	if (!t)
		return 0;
	return t->size;
}

void update(tree t)
{
	if (!t)
		return;

	t->size = len(t->left) + len(t->right) + 1;
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

bool find(tree t, int key)
{
	if (!t)
		return false;
	if (t->x == key)
		return true;
	if (t->x < key)
		return find(t->right, key);

	return find(t->left, key);
}

tree insert(tree t, int x, int y = rand())
{
	if (find(t, x))
		return t;

	tree elem = new node(x, y);
	auto res = split(t, x);
	return merge(merge(res.first, elem), res.second);
}

tree erase(tree t, int x)
{
	auto t12t3 = split(t, x);
	auto t1t2 = split(t12t3.first, x - 1);
	delete t1t2.second;
	return merge(t1t2.first, t12t3.second);
}

int k_max(tree t, int k)
{
	if (!t)
		return 1000000001;
	if (len(t->right) >= k)
		return k_max(t->right, k);
	if (len(t->right) == k - 1)
		return t->x;
	return k_max(t->left, k - len(t->right) - 1);
}

int main()
{
	srand(time(0) + 35418);
	tree t = nullptr;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int r, x;
		cin >> r >> x;
		if (r == +1)
			t = insert(t, x);
		if (r == 0)
			cout << k_max(t, x) << '\n';
		if (r == -1)
			t = erase(t, x);
	}

	return 0;
}