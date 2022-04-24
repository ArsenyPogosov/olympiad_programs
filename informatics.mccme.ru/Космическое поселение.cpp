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

	long long n, a, b, x, y;
	fin >> n >> a >> b >> x >> y;
	long long l{ 0 }, r{1000000000000000000}, mid;
	while (l + 1 < r)
	{
		mid = (l + r) / 2;
		if (max((x / (a + 2 * mid))*(y / (b + 2 * mid)), (x / (b + 2 * mid))*(y / (a + 2 * mid))) >= n)
			l = mid;
		else
			r = mid;
	}

	fout << l;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}