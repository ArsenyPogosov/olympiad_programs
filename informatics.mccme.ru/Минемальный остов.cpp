#include <fstream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n, m;
	fin >> n >> m;
	vector<pair<int, pair<int, int>>> Branches(m);
	for (auto &i : Branches)
		fin >> i.second.first >> i.second.second >> i.first;
	for (auto &i : Branches) --i.second.first;
	for (auto &i : Branches) --i.second.second;
	sort(Branches.begin(), Branches.end());

	int count = 0, answ = 0;
	vector<int> ForestNum(n);
	for (int i = 0; i <= n - 1; ++i) ForestNum[i] = i;

	int h;
	for (int i = 0; count <n - 1; ++i)
		if (ForestNum[Branches[i].second.first] != ForestNum[Branches[i].second.second])
		{
			++count;
			answ += Branches[i].first;

			h = ForestNum[Branches[i].second.second];
			for (auto &j : ForestNum)
				if (j == h) j = ForestNum[Branches[i].second.first];
		}

	fout << answ;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}