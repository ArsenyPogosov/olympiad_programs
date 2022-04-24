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

	int n;
	fin >> n;
	vector<pair<int, int>> zaiavki(n);
	for (auto&i : zaiavki)
		fin >> i.second >> i.first;
	sort(zaiavki.begin(), zaiavki.end());
	vector<int> dp(1441);


	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}