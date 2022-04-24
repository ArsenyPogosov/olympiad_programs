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
	void Add(string &s, int isterm = -1)
	{
		Node* it = this;
		int i = 0;
		while (i < s.size())
		{
			if (!(it->link[tolower(s[s.size() - i - 1]) - f])) it->Add(tolower(s[s.size() - i - 1]) - f);
			it = it->link[tolower(s[s.size() - i - 1]) - f];
			++i;
		}
		it->term = isterm;
	}
};

typedef Node* Bor;

int main()
{
	ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
	
	int n; 
	string s; 
	cin >> n >> s;
	int m;
	cin >> m;
	vector<string> sl(m);
	Bor bor = new Node();
	for (int i = 0; i < m; ++i)
	{
		cin >> sl[i];

		bor->Add(sl[i], i);
	}
	vector<bool> dp(n);
	vector<int> p(n, -1);
	for (int i = n - 1; i >= 0; --i)
	{
		Bor it = bor;
		for (int len = 1; i + len <= n && len <= 1000; ++len)
		{
			int j = i + len - 1;
			it = it->move(s[j] - f);
			if (!it) break;
			if (it->term != -1)
			{
				int ind = it->term;
				int ni = i + sl[ind].size();
				if (ni >= n || dp[ni]) { dp[i] = true; p[i] = ind; break; }
			}
		}
	}
	int it = 0;
	while (it < n)
	{
		cout << sl[p[it]] << ' ';
		it += sl[p[it]].size();
	}

	return 0;
}