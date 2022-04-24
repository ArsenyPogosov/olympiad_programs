#include <fstream>
//#include <vector>
//#include <queue>
#include <vector>
#include <set>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	long long n, k;
	fin >> n >> k;
	vector<pair<long long, long long>> Squere(n);
	for (auto&i : Squere)
		fin >> i.first >> i.second;
	if (k < n)
	{
		sort(Squere.begin(), Squere.end());
		long long BestMinX{ Squere[n - k].first };
		set<pair<long long, long long>> BestY;
		for (long long i = n - k; i <= n - 1; ++i)
			BestY.insert({ Squere[i].second, Squere[i].first });
		Squere.erase(Squere.begin() + n - k, Squere.end());
		set<pair<long long, long long>>::iterator it = BestY.begin();
		long long maxS = BestMinX*(it->first);
		BestY.insert({ Squere[n - k - 1].second, Squere[n - k - 1].first });
		if (pair<long long, long long>{ Squere[n - k - 1].second, Squere[n - k - 1].first } > *it)
			++it;
		for (long long kk = n - k - 1; kk >= 1; --kk)
		{
			maxS = max(maxS, Squere[kk].first*(it->first));
			BestY.insert({ Squere[kk - 1].second, Squere[kk - 1].first });
			if (pair<long long, long long>{ Squere[kk - 1].second, Squere[kk - 1].first } > *it)
				++it;
		}
		maxS = max(maxS, Squere[0].first*(it->first));
		fout << maxS;
	}
	else
	{
		long long x = 199999999, y = 199999999;
		for (auto&i : Squere)
		{
			x = min(x, i.first);
			y = min(y, i.second);
		}

		fout << x*y;
	}

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}