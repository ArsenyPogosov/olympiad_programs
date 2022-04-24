#include <fstream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
#include <string>
using namespace std;

vector<vector<int>> dp;
string s1, s2;

int get(int l1, int l2)
{
	if (l1 == 0)
		return l2;
	if (l2 == 0)
		return l1;
	if (dp[l1][l2] != -1)
		return dp[l1][l2];

	dp[l1][l2] = min(get(l1 - 1, l2 - 1), min(get(l1, l2 - 1), get(l1 - 1, l2))) + 1;
	if (s1[l1 - 1] == s2[l2 - 1]) {
		dp[l1][l2] = min(dp[l1][l2], get(l1 - 1, l2 - 1));
	}
	return dp[l1][l2];
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	fin >> s1 >> s2;
	dp.resize(s1.size() + 1, vector<int>(s2.size() + 1, -1));
	fout << get(s1.size(), s2.size());

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}