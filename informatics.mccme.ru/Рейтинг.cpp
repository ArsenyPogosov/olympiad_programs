#include <fstream>
#include <vector>
#include <iomanip>
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
	vector<int> A(n+1);
	for (int i = 1; i < n + 1; ++i) fin >> A[i];

	vector<vector<double>> dp(n + 1, vector<double>(100, -1));
	vector<vector<int>> parent(n + 1, vector<int>(100, -1));
	for (int i = 1; i <= A[1]; ++i) {
		dp[1][i] = 0;
	}
	for (int i = 2; i <= n; ++i) {
		for (int j = 1; j <= A[i]; ++j) {
			int max = 1;
			for (int k = 1; k <= A[i - 1]; ++k) {
				if (dp[i - 1][max] + double(j) / max < dp[i - 1][k] + double(j) / k)
					max = k;

			}
			
			dp[i][j] = dp[i - 1][max] + double(j) / max;
			parent[i][j] = max;
		}
	}
	int max = 1;
	for (int i = 1; i <= A[n]; ++i)
		if (dp[n][max] < dp[n][i]) max = i;
	fout << fixed << setprecision(3) << dp[n][max] << '\n';
	vector<int> ans;
	int k{ max };
	int count{ n };
	while (count >= 1)
	{
		ans.push_back(k);
		k = parent[count--][k];
	}
	for (int i = n-1; i >= 0; --i)
		fout << ans[i] << ' ';

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}