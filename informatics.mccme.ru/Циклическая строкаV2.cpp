#include <fstream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
#include <string>
using namespace std;

vector<int> ZFunc(string s)
{
	vector<int> res(s.size(), 0);

	int l = 0, r = 0;
	for (int i = 1; i <= s.size() - 1; ++i)
	{
		if (i < r) res[i] = min(res[i - l], r - i + 1);
		while ((res[i] + i <= s.size() - 1) && (s[res[i] + i] == s[res[i]])) ++res[i];
		if (res[i] + i - 1 > r) { l = i; r = res[i] + i - 1; }
	}

	return res;
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	string s;
	fin >> s;
	vector<int> z = ZFunc(s);
	int i = 0;
	for (; i <= s.size() - 1; ++i)
		if (z[i] == s.size() - i) break;
	
	fout << i;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}