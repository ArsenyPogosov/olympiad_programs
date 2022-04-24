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

	long long n;
	fin >> n;
	long long ans = 1;
	for (long long i = 2; i*i <= n; ++i)
	{
		long long count = 0;
		while (n % i == 0)
		{
			n /= i;
			++count;
		}
		ans *= count + 1;
	}
	if (n > 1) ans *= 2;
	fout << ans;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}