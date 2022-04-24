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
	long long res = SupGCD(n, a).second;
	while (res < 0) res += n;

	return res % n;
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

	long long a, n;
	fin >> a >> n;
	
	if (GCD(a+1, n) != 1)
		fout << -1;
	else
	{
		fout << (ob(a + 1, n) - 1 + n) % n;
	}
	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}