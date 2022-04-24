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

	int n, l;
	fin >> n >> l; --l;
	vector<vector<int>> time(n, vector<int>(3));
	for (auto& i : time) fin >> i[0] >> i[1] >> i[2];
	vector<int> shtraph(n, 0);
	for (int i = 0; i <= n-1; ++i)
		for (int step = 0; step <= 2; ++step)
			for (auto& j : time)
			{
				int res1{ 0 }, res2{ 0 };
				for (int k = 0; k <= step; ++k)
				{
					res1 += time[i][k];
					res2 += j[k];
				}
				if (res2 < res1) ++shtraph[i];
			}

	for (int i = 0; i <= n - 1; ++i)
		for (int j = 0; j <= n - 1; ++j)
			if ((shtraph[i] == shtraph[j]) && (j != l) && (i != j))
				shtraph[j] = 1000 * 3 + 1;

	int ans{ 1 };
	for (auto& i : shtraph)
		if (i < shtraph[l]) ++ans;
	fout << ans;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}