#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct node
{
	int x;
	vector<node *> m;
	vector<pair<int, int>> ans;
	node()
	{
		x = 0;
		ans.resize(31, { -1, -1 });
		m.resize(2, nullptr);
	}
};

string bin(int x)
{
	string res(30, '0');
	for (int i = 0; i < 30; ++i)
	{
		res[29 - i] = (x % 2) + '0';
		x /= 2;
	}
	return res;
}

void push(node* root, string x)
{
	if (x == "") ++root->x;
	if (!(root->m[x[0] - '0']))
		root->m[x[0] - '0'] = new node();
	push(root->m[x[0] - '0'], x.substr(1, 30));
}

pair<int, int> Ans(node* root, int k)
{
	if (!root) return { 0, 0 };
	auto a = Ans()
}

int main()
{
	int n, m, k;
	node* root = new node();
	for (int i = 0; i < n; ++i)
	{
		int h; cin >> h; push(root, bin(h));
	}

	return 0;
}