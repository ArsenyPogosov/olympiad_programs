#include <fstream>
//#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
#include <string>
using namespace std;

bool TrueSeq(string s)
{
	if (s.size() == 0)
		return true;
	char left{ s[0] }, right;
	if (left == '(')
		right = ')';
	if (left == '[')
		right = ']';
	if (left == '{')
		right = '}';

	int SuperCount{ 1 };
	bool result;
	for (int i = 1; i <= s.size() - 1; ++i)
	{
		if (s[i] == left) ++SuperCount;
		if (s[i] == right) --SuperCount;
		if (SuperCount == 0)
		{
			result = TrueSeq(s.substr(1, i - 1));
			if (i < s.size() - 1)
				result = result && TrueSeq(s.substr(i + 1, s.size() - i));
			return result;
		}
	}

	return false;
};

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	string s;
	fin >> s;
	if (TrueSeq(s))
		fout << "yes";
	else
		fout << "no";

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}