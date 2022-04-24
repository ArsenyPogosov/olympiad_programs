#include <fstream>
//#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
#include <cmath>
//#include <string>
using namespace std;

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int a, b, c, d;
	fin >> a >> b >> c >> d;
	int MinForPl, MaxForPl, MinForPer, MaxForPer;
	int result{ 0 };
	for (int MinSize = 1; MinSize <= floor(sqrt(b)); ++MinSize)
	{
		MinForPl = max(int(ceil(double(a) / MinSize)), MinSize);
		MaxForPl = int(floor(double(b) / MinSize));
		MinForPer = max(int(ceil(double(c)/2 - MinSize)), MinSize);
		MaxForPer = floor(double(d)/2 - MinSize);

		result += max(min(MaxForPer, MaxForPl) - max(MinForPer, MinForPl) + 1, 0);
	}
	fout << result;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}