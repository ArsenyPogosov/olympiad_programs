#include <fstream>
//#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
#include <string>
using namespace std;

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	string s;
	fin >> s;
	vector<vector<int>> dp(s.size())

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}