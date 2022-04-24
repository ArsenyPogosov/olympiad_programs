#include <fstream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

vector<long long> DirectConnection;
vector<long long> NeighborConnection;
long long n;

pair<long long, long long> Answ(long long it)
{
	if (it == n - 1)
		return{ DirectConnection[it], NeighborConnection[it - 1] };

	pair<long long, long long> res, taken;
	taken = Answ(it + 1);
	res.first = min(DirectConnection[it] + taken.first,
		min(NeighborConnection[it] + taken.first,
			DirectConnection[it] + taken.second));
	if (it == 0)
		res.second = -1;
	else
		res.second = min(NeighborConnection[it - 1] + taken.first,
			NeighborConnection[it - 1] + taken.second);

	return res;
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	fin >> n;
	DirectConnection.resize(n);
	NeighborConnection.resize(n - 1);
	for (auto& i : DirectConnection)
		fin >> i;
	long long h;
	for (auto& i : DirectConnection)
	{
		fin >> h;
		i = min(i, h);
	}
	for (auto& i : NeighborConnection)
		fin >> i;
	/*
	fout << Answ(2).first << ' ' << Answ(2).second << '\n';
	fout << Answ(1).first << ' ' << Answ(1).second << '\n';
	fout << Answ(0).first << ' ' << Answ(0).second << '\n';
	*/
	if (n != 1)
		fout << Answ(0).first;
	else
		fout << DirectConnection[0];

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}