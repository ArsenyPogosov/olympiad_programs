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

	int n, m;
	fin >> n >> m;
	vector<vector<int>> MatSm(n, vector<int>(n, 1000000000));
	int h1, h2, h3;
	for (int i = 0; i <= m - 1; ++i) { fin >> h1 >> h2 >> h3;  MatSm[h1-1][h2-1] = min(MatSm[h1-1][h2-1], h3); }

	vector<long long> Put(n, 1000000000), HelpPut(n);
	Put[0] = 0;

	for (int glub = 0; glub <= n - 1; ++glub, Put = HelpPut)
	{
		HelpPut = vector<long long>(n, 1000000000);
		for (int i = 0; i <= n - 1; ++i)
			for (int j = 0; j <= n - 1; ++j)
				HelpPut[i] = min(min(HelpPut[i], Put[i]), Put[j] + MatSm[j][i]);
	}
	HelpPut = vector<long long>(n, 1000000000);
	for (int i = 0; i <= n - 1; ++i)
		for (int j = 0; j <= n - 1; ++j)
			HelpPut[i] = min(min(HelpPut[i], Put[i]), Put[j] + MatSm[j][i]);

	for (auto& i : Put)
		if (i < 10000000)
			fout << i << ' ';
		else
			fout << 30000 << ' ';

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}