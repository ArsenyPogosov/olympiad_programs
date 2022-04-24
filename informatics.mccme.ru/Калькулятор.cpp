#include <fstream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n;
	fin >> n;
	vector<int> dp(n+1, -1);
	dp[1] = 0;
	for (int i = 2; i <= n; ++i)
	{
		dp[i] = dp[i - 1] + 1;
		if (i % 2 == 0)
			dp[i] = min(dp[i], dp[i / 2] + 1);
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3] + 1);
	}

	fout << dp[n];

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}