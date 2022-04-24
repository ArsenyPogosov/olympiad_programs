#include <fstream>
#include <vector>
#include <string>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <cmath>
using namespace std;

long long power(long long a, long long n)
{
	long long result = 1;
	while (n)
	{
		if (n % 2 == 0)
		{
			a *= a; a %= 1000000009;
			n /= 2;
		}
		else
		{
			result *= a; result %= 1000000009;
			a *= a; a %= 1000000009;
			n /= 2;
		}
	}
	return result;
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n, m;
	fin >> n >> m;
	string str;
	fin >> str;
	vector<bool> ch(26, false);
	m = 0;
	for (int i = 0; i <= str.length()-1; ++i) 
		if (!ch[str[i] - 'a'])
		{
			ch[str[i] - 'a'] = true;
			++m;
		}
	fout << power(m, n);

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}