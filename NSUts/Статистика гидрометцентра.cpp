#include <fstream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
using namespace std;

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n, k;
	fin >> n >> k;
	vector<int> Sum(n);
	int h;
	for (auto& i: Sum)
		for (int j = 1; j <= k; ++j)
		{
			fin >> h;
			i += h;
		}
	vector<pair<int, int>> Limit(n);
	for (auto& i : Limit)
	{
		fin >> i.first;
		fin >> i.second;
		i.first *= k;
		i.second *= k;
	}
	for (int i = 0; i <= n - 1; ++i)
		if ((Limit[i].first <= Sum[i]) && (Sum[i] <= Limit[i].second))
			fout << "YES" << '\n';
		else
			fout << "NO" << '\n';
	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}