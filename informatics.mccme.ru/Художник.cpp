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

	int w, h;
	fin >> w >> h;
	vector<vector<bool>> Map(w, vector<bool>(h, true));
	int n;
	fin >> n;
	for (int i = 0; i < n; ++i)
	{
		int a, b, c, d; 
		fin >> a >> b >> c >> d;
		for (int j = a; j <= c - 1; ++j)
			for (int k = b; k <= d - 1; ++k)
				Map[j][k] = false;
	}
	int count{ 0 };
	for (auto&i : Map)
		for (int j = 0; j <= h-1; ++j)
			if (i[j]) ++count;
	fout << count;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}