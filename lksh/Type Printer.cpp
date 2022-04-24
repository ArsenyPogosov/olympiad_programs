#include <fstream>
#include <stack>
#include <list>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
#include <string>
using namespace std;

const int ALP = 'z' - 'a' + 1;

ifstream cin("printer.in");
ofstream cout("printer.out");

struct node
{
	char symb;
	node *p;
	node **link;
	bool term;

	int len;
	int lenkey;
	node(char c = '$')
	{
		symb = c;
		p = nullptr;
		link = new node*[ALP];
		for (int i = 0; i < ALP; ++i)
			link[i] = nullptr;
		term = false;

		len = 1;
		lenkey = -1;
	}
};
typedef node* trie;

void add(trie root, string s)
{
	if (!root)
		return;

	trie curr = root;
	stack<pair<trie, int>> toFix;
	for (auto&c : s)
	{
		toFix.push({ curr, c - 'a'});
		if (!curr->link[c - 'a'])
		{
			curr->link[c - 'a'] = new node(c);
			curr->link[c - 'a']->p = curr;
		}
		curr = curr->link[c - 'a'];
	}
	curr->term = true;
	while (!toFix.empty())
	{
		trie t = toFix.top().first;
		int key = toFix.top().second;
		toFix.pop();
		if (t->len < t->link[key]->len + 1)
		{
			t->len = t->link[key]->len + 1;
			t->lenkey = key;
		}
	}
}

list<char> res;

void ReturnTrip(trie t)
{
	if (t->term)
		res.push_back('P');
	for (int i = 0; i < ALP; ++i)
		if (t->link[i])
		{
			res.push_back(t->link[i]->symb);
			ReturnTrip(t->link[i]);
			res.push_back('-');
		}
}

void Trip(trie t)
{
	if (t->term)
		res.push_back('P');
	for (int i = 0; i < ALP; ++i)
		if (i != t->lenkey)
			if (t->link[i])
			{
				res.push_back(t->link[i]->symb);
				ReturnTrip(t->link[i]);
				res.push_back('-');
			}
	int i = t->lenkey;
	if (i >= 0)
	{
		res.push_back(t->link[i]->symb);
		Trip(t->link[i]);
	}
}

int main()
{
	int n;
	cin >> n;
	trie t = new node;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		add(t, s);
	}
	Trip(t);
	cout << res.size() << '\n';
	for (auto&i : res)
		cout << i << '\n';

	cin.close();
	cout.close();
	return 0;
}