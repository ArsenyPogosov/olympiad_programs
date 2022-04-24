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

	long long n;
	fin >> n;
	vector<long long> bot(n);
	for (auto& i : bot)
		fin >> i;

	sort(bot.begin(), bot.end());
	vector<long long> need(n), can(n+1);
	need[0] = 0;
	for (long long i = 1; i <= n - 1; ++i)
		need[i] = need[i - 1] + (bot[i] - bot[i - 1])*i;
	
	can[n] = 0;
	for (long long i = n - 1; i >= 0; --i)
		can[i] = can[i + 1] + bot[i];

	for (long long i = n - 1; i >= 0; --i)
		if (need[i] <= can[i+1]) { fout << n - i - 1; break; }

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}