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
	vector<int> A(n), B(n), C(n);
	for (int i = 0; i <= n - 1; ++i)
		fin >> A[i] >> B[i] >> C[i];
	vector<int> dp(n);
	dp[0] = A[0];
	if (n >= 2)
		dp[1] = min(A[0] + A[1], B[0]);
	if (n >= 3)
		dp[2] = min(A[2] + dp[1], min(B[1] + dp[0], C[0]));
	for (int i = 3; i <= n - 1; ++i)
		dp[i] = min(A[i] + dp[i - 1], min(B[i - 1] + dp[i - 2], C[i - 2] + dp[i - 3]));

	fout << dp[n - 1];

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}