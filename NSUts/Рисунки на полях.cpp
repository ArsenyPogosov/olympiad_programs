#include <fstream>
//#include <vector>
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
	int minX{ 30001 }, maxX{ -30001 }, maxAbY{ 0 };
	int x, y;
	bool findY0{ false };
	for (; n >= 1; --n)
	{
		fin >> x >> y;
		maxAbY = max(maxAbY, abs(y));
		if (y == 0)
		{
			findY0 = true;
			minX = min(minX, x);
			maxX = max(maxX, x);
		}
	}

	if (findY0)
		fout << round((maxX - minX)*maxAbY / 2.0);
	else
		fout << 0;


	fin.close();  //close input file
	fout.close(); //close output file

	return 0; 
}