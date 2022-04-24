#include <fstream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
#include <string>
using namespace std;

vector<int> zFunc(string s)
{
	vector<int> res(s.size());
	res[0] = 0;
	int l{ 0 }, r{ 0 };
	for (int i = 1; i <= s.size() - 1; ++i)
	{
		res[i] = max(0, min(r - i, res[i - l]));
		while (s[res[i]] == s[res[i] + i]) ++res[i];
		if (res[i] + i > r) { r = res[i] + i; l = i; }
	}

	return res;
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	string s, s2;
	fin >> s >> s2;
	vector<int> Z{ zFunc(s + '&' + s2 + s2) };
	int i;
	bool flag{ false };
	for (i = 1; i <= s.size() + 1 + s2.size() * 2 - 1; ++i)
		if (Z[i] == s.size()) { flag = true; break; }
	if (flag)
		fout << i - (int)s.size() - 1;
	else
		fout << -1;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}