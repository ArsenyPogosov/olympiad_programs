#include <fstream>
//#include <vector>
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

	long long a, k, b, m, x;
	fin >> a >> k >> b >> m >> x;
	long long l = 0, r = 2 * x / (a + b) + 10;
	while (l + 1 < r)
	{
		long long mid = (l + r) / 2;
		if ((mid - mid / k)*a + (mid - mid / m)*b >= x)
			r = mid;
		else
			l = mid;
	}

	fout << r;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}