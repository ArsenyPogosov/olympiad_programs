#include <fstream>
#include <stack>
#include <list>
#include <list>
//#include <map>
#include <algorithm>
//#include <math>
#include <string>
using namespace std;

const int ALP = 'z' - 'a' + 1;

ifstream cin("prof.in");
ofstream cout("prof.out");

struct node
{
	char symb;
	list<node*> link;

	int fop;
	bool checked;
	node(char c = '$')
	{
		symb = c;

		fop = -1;
		checked = false;
	}
};
typedef node* trie;

int res = 0;

void add(trie root, string s, int op)
{
	if (!root)
		return;

	trie curr = root;
	for (int i = op; i < s.size() && (i - op + 1 <= s.size() / 2); ++i)
	{
		char c = s[i];
		trie next = nullptr;
		for (auto&i : curr->link)
			if (i->symb == c)
			{
				next = i;
				break;
			}
		if (!next)
		{
			if (i - op + 1 > (s.size() - op) / 2)
				return;
			next = new node(c);
			next->fop = i;
			curr->link.push_back(next);
		}
		curr = next;
		if ((curr->fop < op) && (!curr->checked))
		{
			++res;
			curr->checked = true;
		}
	}
}

int main()
{
	string s;
	cin >> s;
	trie t = new node;
	for (int i = 0; i < s.size(); ++i)
		add(t, s, i);
	cout << res;
	
	cin.close();
	cout.close();
	return 0;
}