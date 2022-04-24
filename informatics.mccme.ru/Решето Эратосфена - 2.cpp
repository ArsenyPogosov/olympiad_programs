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

	int n;
	fin >> n;
	vector<bool> prime(n + 1, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i*i <= n; ++i)
		if (prime[i])
			for (int j = i*i; j <= n; j += i)
				prime[j] = 0;
	for (int i = 0; i <= n; ++i)
		if (prime[i])
			fout << i << ' ';

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}