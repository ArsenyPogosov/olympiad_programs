//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/260097/problem/E
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

const int f = 'a', ALP = 'z' - 'a' + 1;

vector<list<int>> Graph(ALP);
vector<int> fire(ALP), tout(ALP);
bool cycle = false, contrad = false;
int t = 0;

void TSDFS(int v)
{
	++t;
	fire[v] = 1;
	for (auto& i : Graph[v])
	{
		if (fire[i] == 0)
			TSDFS(i);
		if (fire[i] == 1)
		{
			cycle = true;
			return;
		}
	}
	fire[v] = 2;
	tout[v] = t++;
}

void build(string& s1, string& s2)
{
	int it1 = 0, it2 = 0;
	while (it1 < s1.size() && it2 < s2.size())
	{
		if (s1[it1] != s2[it2])
		{
			Graph[s2[it2] - f].push_back(s1[it1] - f);
			return;
		}
		++it1; ++it2;
	}
	if (it2 >= s2.size())
	{
		contrad = true;
	}
}

int main()
{
	int n; cin >> n;
	vector<string> s(n);
	for (auto& i : s) cin >> i;

	for (int i = 0; i < n && !contrad; ++i)
		for (int j = i + 1; j < n && !contrad; ++j)
			build(s[i], s[j]);

	for (int i = 0; i < ALP && !contrad; ++i)
		if (!fire[i])
			TSDFS(i);

	if (cycle || contrad)
	{
		cout << "Impossible\n";
	}
	else
	{
		vector<int> ts(ALP);
		iota(ts.begin(), ts.end(), 0);
		sort(ts.begin(), ts.end(), [&](int a, int b) {
			return tout[a] < tout[b];
			});

		for (auto& i : ts) cout << char(f + i);
	}

	return 0;
}