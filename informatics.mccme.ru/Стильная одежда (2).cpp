#include <fstream>
#include <vector>
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

	int n1, n2, n3, n4;
	fin >> n1;
	vector<int> N1(n1);
	for (auto&i : N1)
		fin >> i;
	fin >> n2;
	vector<int> N2(n2);
	for (auto&i : N2)
		fin >> i;
	fin >> n3;
	vector<int> N3(n3);
	for (auto&i : N3)
		fin >> i;
	fin >> n4;
	vector<int> N4(n4);
	for (auto&i : N4)
		fin >> i;
	sort(N1.begin(), N1.end());
	sort(N2.begin(), N2.end());
	sort(N3.begin(), N3.end());
	sort(N4.begin(), N4.end());
	int a{ 0 }, b{ 0 }, c{ 0 }, d{ 0 }, M;
	while (true)
	{
		M = min(a, min(b, min(c, d)));
		if (M == a)
		{
			++a;
			if (a >= n1)
				break;
		}
		if (M == b)
		{
			++b;
			if (b >= n2)
				break;
		}
		if (M == c)
		{
			++c;
			if (c >= n3)
				break;
		}
		if (M == d)
		{
			++d;
			if (d >= n4)
				break;
		}
		if (max(N1[a], max(N2[b], max(N3[c], N4[d]))))
	}
	while(true)

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}