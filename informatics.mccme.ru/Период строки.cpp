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
	ifstream fin("input.txt");   //open input file
	ofstream fout("output.txt"); //open output file

	string s;
	fin >> s;
	vector<int> Z{ zFunc(s) };
	int i;
	for (i = 1; i <= s.size() - 1; ++i)
		if ((Z[i] == s.size() - i)&&(s.size() % i == 0)) break;
	fout << s.size()/i;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}
