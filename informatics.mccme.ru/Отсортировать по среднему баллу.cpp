#include <fstream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
#include <string>
using namespace std;

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n;
	fin >> n;
	vector<pair<int, int>> UltimatePowerfullVec(n);
	vector<string> buidlo(n);
	int h1, h2, h3;
	string sh1, sh2;
	for (int i = 0; i <= n-1; ++i)
	{
		fin >> sh1 >> sh2 >> h1 >> h2 >> h3;
		buidlo[i] = sh1 + ' ' + sh2;
		UltimatePowerfullVec[i].second = i;
		UltimatePowerfullVec[i].first = - h1 - h2 - h3;
	}
	sort(UltimatePowerfullVec.begin(), UltimatePowerfullVec.end());
	for (auto&i : UltimatePowerfullVec)
		fout << buidlo[i.second] << '\n';

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}