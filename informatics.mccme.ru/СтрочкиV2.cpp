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
		res[i] = min(0, max(r - i + 1, res[i - l]));
		while ((i + res[i] <= s.size() - 1) && (s[i + res[i]] == s[res[i]])) ++res[i];
		if (i + res[i] - 1 > r) { l = i; r = i + res[i] - 1; }
	}

	return res;
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	string s1, s2;
	fin >> s1 >> s2;
	vector<int> z = ZFunc(s1 + '&' + s2 + s2);
	int res = -1;
	for (int i = s1.size()+1; i <= s1.size()+s2.size(); ++i)
		if (z[i] == s1.size()) { res = i - s1.size() - 1; break; }

	fout << res;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}