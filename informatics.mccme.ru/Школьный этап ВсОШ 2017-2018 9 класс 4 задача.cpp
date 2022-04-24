// Example program
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	ifstream fin("input.txt");
	ofstream fout("output.txt");

	long long n;
	fin >> n;
	vector<long long> Pay(n);
	for (long long i = 0; i <= n - 1; ++i) fin >> Pay[i];
	vector<long long> LocRes(n, 0);
	LocRes[0] = Pay[0];
	LocRes[1] = Pay[1];

	for (long long i = 2; i <= n - 1; ++i)
		LocRes[i] = min(LocRes[i - 1], LocRes[i - 2]) + Pay[i];

	fout << min(LocRes[n - 1], LocRes[n - 2]);

	fin.close();
	fout.close();

	return 0;
}

