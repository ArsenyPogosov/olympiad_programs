#include <fstream>
#include <vector>
#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

vector<int> F;

int C(int n, int k)
{

	return F[n] / F[k] / F[n - k];
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n, m;
	fin >> n >> m;
	vector<pair<int, vector<int>>> Ch(n);
	int h;
	vector<bool> IsRoot(n, true);
	for (auto& i : Ch)
	{
		fin >> h;
		i.second.resize(h);
		for (auto& j : i.second) { fin >> j; --j;  IsRoot[j] = false; }
		fin >> i.first;
	}
	vector<int> depth(n, -1);
	queue<int> Q;
	for (int i = 0; i <= n - 1; ++i)
		if (IsRoot[i])
		{
			Q.push(i);
			depth[i] = 1;
		}
	queue<int> QQ;
	while (Q.size())
	{
		for (auto& i: Ch[Q.front()].second)
			if (depth[i] == -1)
			{
				depth[i] = depth[Q.front()] + 1;
				Q.push(i);
				if (depth[i] <= m) QQ.push(i);
			}
		Q.pop();
	}

	F.resize(n+1);
	F[0] = 1;
	for (int i = 1; i <= n; ++i) { F[i] = F[i - 1] * i; F[i] %= 1000000007; }
	int res{ 0 };
	while (QQ.size())
	{
		res += C(n- depth[QQ.front(),m-depth[QQ.front()])
	}

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}