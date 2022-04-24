#include <iostream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
#include <string>
using namespace std;

int main()
{
	//ifstream cin("input.txt");	 //open input file
	//ofstream cout("output.txt"); //open output file

	long long n, m;
	cin >> n >> m;
	vector<pair<long, long>> Cost(m);
	vector<pair<long, long>> Heap(m, { 0 , 0 });

	for (auto& i : Cost) cin >> i.first >> i.second;

	string h;
	long long h1, h2;
	for (long long i = 0; i <= n - 1; ++i)
	{
		cin >> h >> h1 >> h2;
		if (h == "pen") Heap[h1-1].first += h2;
		else Heap[h1-1].second += h2;//
	}

	long long count{ 0 };
	for (long long i = 0; i <= m-1; ++i)
	{
		count += abs(Heap[i].first - Heap[i].second)*min(Cost[i].first, Cost[i].second);
	}
	cout << count;

	//cin.close();  //close input file
	//cout.close(); //close output file

	return 0;
}