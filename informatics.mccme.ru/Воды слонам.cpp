#include <fstream>
#include <vector>
#include <deque>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

vector<int> cost;

pair<int, int> better(pair<int, int> a, pair<int, int> b)
{
	if (a == pair<int, int>{-1, -1}) return b;
	if (b == pair<int, int>{-1, -1}) return a;

	if (cost[a.second] * cost[b.first] >= cost[b.second] * cost[a.first])
		return a;

	return b;
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n;
	fin >> n;
	cost.resize(n);
	for (auto&i : cost)
		fin >> i;

	deque<int> Q;
	for (int i = 0; i <= n - 1; ++i)
	{
		while ((Q.size() > 0) && (cost[Q.back()] < cost[i]))
			Q.pop_back();
		Q.push_back(i);
	}

	pair<int, int> best{ -1, -1 };
	for (int i = 0; i <= n - 1; ++i)
	{
		while ((Q.size() > 0) && (Q.front() <= i))
			Q.pop_front();
		if (Q.size() > 0)
			best = better(best, { i, Q.front() });
	}

	if (cost[best.first] == cost[best.second]) best = { -1, -1 };
	fout << best.first + 1 << ' ' << best.second + 1;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}