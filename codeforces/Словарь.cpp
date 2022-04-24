//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/259345/problems
//status: coding

#include <bits/stdc++.h>
using namespace std;
//#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif
#pragma endregion

const int Alp = 'z' - 'a' + 2, f = 'a';

struct Node
{
	vector<Node*> link;
	int letter;
	int term;
	Node() { letter = -1; term = -1; link.resize(Alp); }
	Node(int _l, int isterm = -1) { letter = _l; term = isterm; link.resize(Alp); }
	Node* move(int l) { return link[l]; }
	void Add(int _l, int isterm = -1) { link[_l] = new Node(_l, isterm); }
	void Add(string s, int isterm = -1)
	{
		Node* it = this;
		int i = 0;
		while (i < s.size())
		{
			if (!(it->link[s[i] - f])) it->Add(s[i] - f);
			it = it->link[s[i] - f];
			++i;
		}
		it->term = isterm;
	}
};

typedef Node* Bor;

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	string s; cin >> s; int n; cin >> n;

	Bor bor = new Node();
	for (int i = 0; i < n; ++i)
	{
		string h; cin >> h;
		bor->Add(h, i);
	}
	vector<bool> res(n);
	n = s.size();
	for (int i = 0; i < n; ++i)
	{
		Bor it = bor;
		for (int len = 1; i + len <= n && len <= 30; ++len)
		{
			int j = i + len - 1;
			it = it->move(s[j] - f);
			if (!it) break;
			if (it->term != -1) res[it->term] = true;
		}
	}
	for (auto i : res)
		if (i)
			cout << "Yes\n";
		else
			cout << "No\n";

	return 0;
}