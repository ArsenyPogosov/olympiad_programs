#include <fstream>
//#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

pair<long long, long long> SupGCD(long long a, long long b)
{
	if (b == 0) return{ 1 , 0 };
	pair<long long, long long> h = SupGCD(b, a % b);

	return{ h.second, (h.first - a / b * h.second) };
}

long long ob(long long a, long long n)
{
	return (SupGCD(n, a).second) % n;
}

long long GCD(long long a, long long b)
{
	if (b == 0) return a;
	return GCD(b, a % b);
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	long long A1, N1;
	fin >> A1 >> N1;

	long long a = (A1 + 1) % N1, b = (N1 - A1) % N1, n = N1; // ax = b (mod n)
	long long g = GCD(a, n);
	if (b % g != 0)
	{
		fout << -1;

		fin.close();  //close input file
		fout.close(); //close output file

		return 0;
	}
	a /= g; b /= g; n /= g;
	fout << (b*ob(a, n) + 5 * n) % n;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}