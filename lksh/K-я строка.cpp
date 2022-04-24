#include <fstream>
//#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
#include <string>
using namespace std;

const int ALP = 'z' - 'a' + 1;

struct node
{
	char symb;
	node *p;
	node **link;
	bool term;

	int size;
	node(char c = '$')
	{
		symb = c;
		p = nullptr;
		link = new node*[ALP];
		for (int i = 0; i < ALP; ++i)
			link[i] = nullptr;
		term = false;

		size = 0;
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
		++curr->size;
		if (!curr->link[c - 'a'])
		{
			curr->link[c - 'a'] = new node(c);
			curr->link[c - 'a']->p = curr;
		}
		curr = curr->link[c - 'a'];
	}
	++curr->size;
	curr->term = true;
}

trie kterm(trie root, int k)
{
	if (!root)
		return nullptr;

	if (k == 1 && root->term)
		return root;
	if (root->term)
		--k;

	for (int i = 0; i < ALP; ++i)
		if (root->link[i])
		{
			if (root->link[i]->size >= k)
				return kterm(root->link[i], k);
			else
				k -= root->link[i]->size;
		}

	return nullptr;
}

string NodeS(trie root)
{
	if (!root)
		return "";

	string res = "";
	while (root->p)
	{
		res += root->symb;
		root = root->p;
	}

	reverse(res.begin(), res.end());
	return res;
}

int main()
{
	ifstream cin("kthstr.in");
	ofstream cout("kthstr.out");
	int n;
	cin >> n;
	trie t = new node;
	for (int i = 0; i < n; ++i)
	{
		string s;
		cin >> s;
		if ('a' <= s[0] && s[0] <= 'z')
			add(t, s);
		else
			cout << NodeS(kterm(t, stoi(s))) << '\n';
	}

	cin.close();
	cout.close();
	return 0;
}