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
	vector<int> height(n);
	for (auto&i : height)
		fin >> i;
	int l

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}