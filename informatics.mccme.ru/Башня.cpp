#include <fstream>
#include <vector>
//#include <queue>
#include <list>
//#include <map>
#include <algorithm>
#include <cmath>
//#include <string>
using namespace std;

long long n, k;
vector<long long> fort;
vector<long long> towerPower;
vector<pair<long long, list<long long>>> answer;

pair<long long, list<long long>> solve(long long sufI)
{
	if (sufI > n - k) return{ 0, {} };
	if (answer[sufI].first != -1) return answer[sufI];

	pair<long long, list<long long>> res1, res2;
	res1 = solve(sufI + 1); res2 = solve(sufI + k);
	res2.first += towerPower[sufI];
	res2.second.push_front(sufI);
	if (res1.first > res2.first)
	{
		answer[sufI] = res1;
		return res1;
	}
	answer[sufI] = res2;
	return res2;
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	fin >> n >> k;
	fort = vector<long long>(n);
	for (auto&i : fort) fin >> i;
	n = 100000;
	fort = vector<long long>(n);
	for (int i = 0; i <= n - 1; ++i) fort[i] = i;

	vector<long long> towerLenght = vector<long long>(n - k + 1, 0);
	vector<long long> towerMin = vector<long long>(n - k + 1, 10000000);
	towerPower = vector<long long>(n - k + 1);

	for (long long i = 0; i <= k - 1; ++i)
		towerLenght[0] += fort[i];
	for (long long i = 1; i <= n - k; ++i)
		towerLenght[i] = towerLenght[i - 1] + fort[i + k - 1] - fort[i - 1];

	vector<long long> pref, suf;
	pref = suf = vector<long long>(n);
	for (long long i = 0; i <= n - 1; ++i)
		if ((k == 1) || (i % (k - 1) == 0))
			pref[i] = fort[i];
		else
			pref[i] = min(fort[i], pref[i - 1]);
	for (long long i = n - 1; i >= 0; --i)
		if ((k == 1) || (i % (k - 1) == k - 2) || (i == n - 1))
			suf[i] = fort[i];
		else
			suf[i] = min(fort[i], suf[i + 1]);
	for (long long i = 0; i <= n - k; ++i)
		towerMin[i] = min(suf[i], pref[i + k - 1]);

	for (long long i = 0; i <= n - k; ++i)
		towerPower[i] = towerLenght[i] * towerMin[i];

	answer = vector<pair<long long, list<long long>>>(n - k + 1, pair<long long, list<long long>>{ -1, {} });
	for (int i = n - k; i >= 0; --i) solve(i);
	list<long long> res;
	res = solve(0).second;

	fout << res.size() << '\n';
	for (auto&i : res)
		fout << i + 1 << ' ';

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}