#include <fstream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n;
	fin >> n;
	vector<int> W(n);
	for (auto&i : W)
		fin >> i;
	int s{ 0 };
	for (auto&i : W) s += i;
	vector<vector<bool>> dp(n, vector<bool>(10001, false));
	dp[0][W[0]] = true;
	dp[0][0] = true;
	for (int i = 1; i <= n - 1; ++i)
		for (int j = 0; j <= 10000; ++j)
		{
			dp[i][j] = dp[i - 1][j];
			if (j >= W[i])
				dp[i][j] = dp[i][j] || dp[i - 1][j - W[i]];
		}
	if (s % 2 == 1)
		fout << "NO";
	else
		if (dp[n - 1][s / 2])
			fout << "YES";
		else
			fout << "NO";

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}