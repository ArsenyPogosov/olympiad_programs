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

	int n, l;
	fin >> n >> l;
	vector<vector<int>> Res(n, vector<int>(3));
	for (auto& i : Res)
		for (auto& j : i)
			fin >> j;

	vector<int> LocTime(n), TotRes(n, 0);
	for (int i = 0; i <= 2; ++i)
	{
		for (int j = 0; j <= n - 1; ++j)
		{
			LocTime[j] = 0;
			for (int h = 0; h <= i; ++h)
				LocTime[j] += Res[j][h];
		}

		for (int j = 0; j <= n - 1; ++j)
			for (int k = 0; k <= n - 1; ++k)
			{
				if (LocTime[j] > LocTime[k]) ++TotRes[j];
				if (LocTime[j] < LocTime[k]) ++TotRes[k];
			}
	}
	int mesto{ 1 };
	for (auto& i : TotRes)
		if (i < TotRes[l - 1]) ++mesto;

	fout << mesto;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}