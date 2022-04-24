#include <fstream>
//#include <vector>
//#include <queue>
//#include <list>
#include <unordered_set>
//#include <algorithm>
//#include <math>
#include <string>
using namespace std;

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	char regime; 
	string s;
	fin >> regime;
	unordered_set<string> dict;
	while (regime != '#')
	{
		fin >> s;
		if (regime == '+') dict.insert(s);
		if (regime == '-') dict.erase(s);
		if (regime == '?') dict.find(s) != dict.end()? fout << "YES\n" : fout << "NO\n";
		fin >> regime;
	}

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}