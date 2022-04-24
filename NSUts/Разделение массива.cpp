#include <fstream>
#include <vector>
//#include <queue>
#include <list>
//#include <map>
#include <algorithm>
#include <cmath>
//#include <string>
using namespace std;

vector<bool> isPrime;

void InitializeIsPrime(int num)
{
	isPrime.resize(num, true);

	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i <= sqrt((double)num); ++i)
		if (isPrime[i])
			for (int j = i * i; j <= num - 1; j += i)
				isPrime[j] = false;
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n;
	fin >> n;
	list<int> NotPrime;
	InitializeIsPrime(1000001);
	int h;
	for (int i = 0; i <= n - 1; ++i)
	{
		fin >> h;
		if (isPrime[h])
			fout << h << ' ';
		else
			NotPrime.push_back(h);
	}
	while (!NotPrime.empty())
	{
		fout << NotPrime.front() << ' ';
		NotPrime.pop_front();
	}

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}