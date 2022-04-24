#include <iostream>
#include <ctime>
#include <random>
//#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

const int INF = 1000000001;

struct Node
{
	int data;
	int y;
	Node *left;
	Node *right;
	int size;
	int min;
	bool reverse;
	Node(int _data, int _y = rand())
	{
		data = _data;
		y = _y;
		size = 1;
		min = data;
		reverse = false;
		left = right = nullptr;
	}
	~Node()
	{
		delete left;
		delete right;
	}
};
typedef Node* tree;

int len(tree t)
{
	if (!t)
		return 0;
	return t->size;
}

int min(tree t)
{
	if (!t)
		return INF;
	return t->min;
}

void update(tree t)
{
	if (!t)
		return;

	t->size = len(t->left) + len(t->right) + 1;
	t->min = min(min(min(t->left), min(t->right)), t->data);
}

void push(tree t)
{
	if (!t)
		return;

	if (t->reverse)
	{
		swap(t->left, t->right);
		if (t->left)
			t->left->reverse ^= true;
		if (t->right)
			t->right->reverse ^= true;
		t->reverse = false;
	}
}

pair<tree, tree> split(tree t, int k)
{
	if (!t)
		return{ nullptr, nullptr };
	push(t);
	int l = len(t->left);
	if (l >= k)
	{
		auto res = split(t->left, k);
		t->left = res.second;
		update(t);
		return{ res.first, t };
	}
	auto res = split(t->right, k - l - 1);
	t->right = res.first;
	update(t);
	return{ t, res.second };
}

tree merge(tree t1, tree t2)
{
	if (!t1)
		return t2;
	if (!t2)
		return t1;
	push(t1);
	push(t2);

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

tree insert(tree t, int data, int k = -1)
{
	if (k == -1)
		k = len(t);
	tree elem = new Node(data);
	auto res = split(t, k);
	return merge(res.first, merge(elem, res.second));
}

int min(tree &t, int l, int r)
{
	auto t1t23 = split(t, l);
	auto t2t3 = split(t1t23.second, r - l + 1);
	int m = min(t2t3.first);
	t = merge(t1t23.first, merge(t2t3.first, t2t3.second));
	return m;
}

tree reverse(tree t, int l, int r)
{
	auto t1t23 = split(t, l);
	auto t2t3 = split(t1t23.second, r - l + 1);
	t2t3.first->reverse ^= true;
	return merge(t1t23.first, merge(t2t3.first, t2t3.second));
}

int main()
{
	srand(time(0) + 7421);
	tree t = nullptr;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		int h;
		cin >> h;
		t = insert(t, h);
	}
	for (int i = 0; i < m; ++i)
	{
		int h, l, r;
		cin >> h >> l >> r;
		if (h == 1)
			t = reverse(t, l - 1, r - 1);
		if (h == 2)
			cout << min(t, l - 1, r - 1) << '\n';
	}

	return 0;
}