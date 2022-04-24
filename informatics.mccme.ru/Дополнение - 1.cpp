#include <fstream>
#include <vector>
#include <queue>
#include <list>
//#include <map>
//#include <algorithm>
#include <cmath>
//#include <string>
using namespace std;

const int INF = 1000000000;

vector<vector<int>>cheapest;
int ans(vector<bool> mask)
{
	int res{ INF }, MinMost, count{0};
	for (auto&i : mask)
		if (i)
			++count;
	if (count == 1) return 0;

	for (int i = 0; i <= mask.size() - 1; ++i)
		if (mask[i])
		{
			mask[i] = false;
			MinMost = INF;
			for (int j = 0; j <= mask.size() - 1; ++j)
			{
				if (mask[j])
					MinMost = min(MinMost, cheapest[j][i]);
			}
			res = min(res, ans(mask) + MinMost);
		}

	return res;
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n;
	fin >> n;
	vector<list<int>> Graph(n);
	int h;
	vector<vector<int>> Cost(n, vector<int>(n));
	for (auto&i : Cost)
		for (auto&j : i)
			fin >> j;

	for (auto&i : Graph)
		for (int j = 0; j <= n - 1; ++j)
		{
			fin >> h;
			if (h != 0)
				i.push_back(j);
		}

	list<list<int>> podgraph;
	queue<int> Q;
	vector<int> fire(n, INF);
	for (int i = 0; i <= n - 1; ++i)
	{
		if (fire[i] == INF)
		{
			Q.push(i);
			fire[i] = 0;
			podgraph.push_front(list<int>(0));
			while (!Q.empty())
			{
				podgraph.front().push_back(Q.front());
				for (auto&j : Graph[Q.front()])
					if (fire[j] == INF)
					{
						fire[j] = fire[Q.front()] + 1;
						Q.push(j);
					}

				Q.pop();
			}
		}
	}

	cheapest = vector<vector<int>>(podgraph.size(), vector<int>(podgraph.size(), INF));
	list<list<int>>::iterator it1{ podgraph.begin() }, it2;
	for (auto&i : cheapest)
	{
		it2 = podgraph.begin();
		for (auto&j : i)
		{
			if (it1 != it2)
				for (auto&k : *it1)
					for (auto&l : *it2)
						j = min(j, Cost[k][l]);
			++it2;
		}

		++it1;
	}

	vector<bool> mask(cheapest.size(), true);
	fout << ans(mask);

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}