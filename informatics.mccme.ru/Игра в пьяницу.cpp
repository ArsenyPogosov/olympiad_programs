#include <fstream>
//#include <vector>
#include <queue>
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

	queue<int> Q1, Q2;
	int h;
	for (int i = 1; i <= 5; ++i)
	{
		fin >> h;
		Q1.push(h);
	}
	for (int i = 1; i <= 5; ++i)
	{
		fin >> h;
		Q2.push(h);
	}
	int count{ 0 };
	while (!(Q1.empty() || Q2.empty() || count > 1000000))
	{
		++count;
		if (Q1.front() == 0 && Q2.front() == 9)
		{
			Q1.push(Q1.front());
			Q1.push(Q2.front());
		}
		else
		if (Q1.front() == 9 && Q2.front() == 0)
		{
			Q2.push(Q1.front());
			Q2.push(Q2.front());
		}
		else
		if (Q1.front() > Q2.front())
		{
			Q1.push(Q1.front());
			Q1.push(Q2.front());
		}
		else
		{
			Q2.push(Q1.front());
			Q2.push(Q2.front());
		}
		Q1.pop(); Q2.pop();
	}
	if (count > 1000000) fout <<  "botva";
	else
	{
		if (Q2.empty()) fout << "first ";
		else fout << "second ";
		fout << count;
	}
	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}