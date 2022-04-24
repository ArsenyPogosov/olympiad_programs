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
	vector<int> S(n);
	for (auto&i : S)
		fin >> i;
	vector<int> SS(n);
	if (n < 5)
	{
		fout << 0;

		fin.close();  //close input file
		fout.close(); //close output file

		return 0;
	}
	SS[0] = S[0] + S[1] + S[2] + S[3] + S[4];
	for (int i = 1; i <= n - 5; ++i)
		SS[i] = SS[i - 1] - S[i - 1] + S[i + 4];

	vector<vector<bool>> dp(n, vector<bool>(10001, false));
	dp[0][0] = true;
	dp[0][SS[0]] = true;
	for (int i = 1; i <= n - 5; ++i)
		for (int j = 0; j <= 10000; ++j)
		{
			dp[i][j] = dp[i-1][j];
			if ((j > SS[i]) && (i >= 5))
				dp[i][j] = dp[i][j] || dp[i - 5][j - SS[i]];
			if (j == SS[i])
				dp[i][j] = true;
		}
	int max{ 0 };
	for (int j = 0; j <= 10000; ++j)
		if (dp[n - 5][j])
			max = j;
	fout << max * 10;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}