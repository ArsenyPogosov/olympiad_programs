#include <fstream>
//#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
#include <string>
using namespace std;

const int ALP = 126 - 32 + 1;
const char fc = 32;
const char rc = 30;

ifstream cin("console2.in");
ofstream cout("console2.out");

struct node
{
	char symb;
	node *p, *suf, *tsuf;
	node **link;
	bool term;

	node(char c = rc)
	{
		symb = c;
		p = suf = tsuf = nullptr;
		if (c == rc)
			suf = this;
		link = new node*[ALP];
		for (int i = 0; i < ALP; ++i)
			link[i] = nullptr;
		term = false;
	}
};
typedef node* trie;

void add(trie root, string s)
{
	if (!root)
		return;

	trie curr = root;
	for (auto&c : s)
	{
		if (curr->term)
			return;
		if (!curr->link[c - fc])
		{
			curr->link[c - fc] = new node(c);
			curr->link[c - fc]->p = curr;
		}
		curr = curr->link[c - fc];
	}
	curr->term = true;
}

trie suf(trie curr);
trie go(trie curr, char c)
{
	if (curr->link[c - fc])
		return curr->link[c - fc];
	if (!curr->p)
		return curr;
	return go(suf(curr), c);
}

trie suf(trie curr)
{
	if (curr->suf)
		return curr->suf;
	if (!curr->p->p)
		return curr->suf = curr->p;

	return curr->suf = go(suf(curr->p), curr->symb);
}

trie tsuf(trie curr)
{
	if (!curr->p)
		return nullptr;
	if (curr->tsuf)
		return curr->tsuf;

	if (suf(curr)->term)
		return curr->tsuf = suf(curr);
	return curr->tsuf = tsuf(suf(curr));
}

bool check(trie t, string s)
{
	trie curr = t;
	for (auto&i : s)
	{
		curr = go(curr, i);
		if (curr->term)
			return true;
		if (tsuf(curr))
			return true;
	}
	return false;
}

int main()
{
	int n;
	cin >> n;
	trie root = new node;
	string h;
	getline(cin, h);
	for (int i = 0; i < n; ++i)
	{
		string s;
		getline(cin, s);
		add(root, s);
	}
	string s;
	while (getline(cin, s))
	{
		if (check(root, s))
			cout << s << endl;
	}

	cin.close();
	cout.close();
	return 0;
}