#include <fstream>
#include <vector>
//#include <queue>
#include <list>
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
	vector<pair<int, int>> Bad(n);
	vector<pair<int, int>> Place(m);
	for (auto& i : Bad)
		fin >> i.first >> i.second;
	for (auto& i : Place)
		fin >> i.first >> i.second;
	vector<pair<int, pair<int, pair<int, int>>>> TempDes(n * 2 + m * 2);
	int count{ 0 };
	for (auto& i : Bad)
	{
		++count;
		TempDes[count] = { i.first, {1, {-1, -1}} };
		++count;
		TempDes[count] = { i.second,{ -1,{ -1, -1 } } };
	}
	for (int i = 0; i <= m-1; ++i)
	{
		++count;
		TempDes[count] = { Place[i].first,{ 0,{ 0, i } } };
		++count;
		TempDes[count] = { Place[i].second,{ 0,{ 1, i } } };
	}
	sort(TempDes.begin(), TempDes.end(), 
		[](pair<int, pair<int, pair<int, int>>> a, pair<int, pair<int, pair<int, int>>> b)
		->bool
	{if (a.first > b.first) return false; else return true; });

	list<pair<int, list<pair<int, int>>>> TempDesNorm;
	pair<int, list<pair<int, int>>> pushed;
	for (int i = 0; i <= n * 2 + m * 2 - 1; ++i)
	{
		pushed.first = 0;
		pushed.second = {};
		while (TempDes[i + 1].first == TempDes[i].first)
		{
			++i;
			pushed.first += TempDes[i].second.first;
			if (TempDes[i].second.second == pair<int, int>{-1, -1})
				pushed.second.push_back(TempDes[i].second.second);
		}
		TempDesNorm.push_back(pushed);
	}

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}