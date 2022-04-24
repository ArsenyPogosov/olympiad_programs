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
	vector<int> res(s.size(), 0); res[0] = 1;
	int l = 0, r = 0;
	for (int i = 1; i <= s.size() - 1; ++i)
	{
		res[i] = max(0, min(r - i + 1, res[i - l]));
		while ((i + res[i] <= s.size() - 1) && (s[i + res[i]] == s[res[i]])) ++res[i];
		if (i + res[i] - 1 > r) { l = i; r = i + res[i] - 1; }
	}

	return res;
}

vector<int> AFunc(string s)
{
	vector<int> res(s.size(), 0); res[0] = 1;
	vector<int> z = ZFunc(s);
	int l = s.size(), r = s.size();
	for (int i = s.size() - 1; i >= 0; --i)
	{
		res[i] = max(0, min(i - l + 1, z[r - i]));
		while ((i - res[i] >= 0) && (s[i - res[i]] == s[res[i]])) ++res[i];
		if (i - res[i] + 1 < l) { l = i - res[i] + 1; r = i; }
	}

	return res;
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n;
	fin >> n;
	string s;
	fin >> s;
	for (auto&i : AFunc(s)) fout << i << ' ';

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}