#include <fstream>
#include <vector>
//#include <queue>
//#include <list>
#include <map>
//#include <algorithm>
//#include <math>
#include <string>
using namespace std;

int main()
{
	ifstream fin("pies.in");	 //open input file
	ofstream fout("pies.out"); //open output file

	map<string, long long> names;
	long long k;
	fin >> k;
	vector<pair<string, string>> events(k);
	for (auto&i : events) fin >> i.first >> i.second >> i.second;
	long long n;
	fin >> n;
	map<string, long long> types;
	for (long long i = 0; i <= n - 1; ++i)
	{
		string type;
		long long energy;
		fin >> type >> energy;
		types.insert({ type, energy });
	}
	for (auto&i : events)
		names[i.first] += types[i.second];

	for (auto&i : names)
		fout << i.first << ' ' << i.second << '\n';

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}