#include <fstream>
//#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
#include <string>
using namespace std;

bool non(string s)
{
	if (s.size() % 2 == 1) return false;
	if (s[0] == '0' || s[s.size() / 2] == '0') return false;

	for (int i = 0; i <= s.size() / 2 - 1; ++i)
	{
		if (s[i] > s[i + s.size() / 2]) return true;
		if (s[i] < s[i + s.size() / 2]) return false;
	}

	return false;
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	string n, h1, h2;
	fin >> n;
	int count{ 0 };
	for (int i = 1; i <= n.size()/2; ++i)
		if ((n[0] != '0') && (n[i] != '0')) ++count;
	
	if (non(n)) --count;
	fout << count;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}