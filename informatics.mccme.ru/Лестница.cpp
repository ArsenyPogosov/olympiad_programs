#include <fstream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

const int INF = 1000000001;

int m, n;
vector<int> l, h, lSum, hSum, pSum;
vector<vector<int>> res;

int unite(int a, int b)
{
	return hSum[b + 1]*(lSum[b + 1] - lSum[a]) - pSum[b + 1] + pSum[a];
}


int ans(int a, int k)
{
	if (k < 0)
		return INF;
	if (k == 0)
		return 0;
	if (a >= m)
		return INF;
	if (m - a - 1 < k)
		return INF;
	if (res[a][k] != INF)
		return res[a][k];

	for (int i = a; i < m; ++i)
		res[a][k] = min(res[a][k], unite(a, i) + ans(i + 1, k - i + a));
	return res[a][k];
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	fin >> m >> n;
	l.resize(m);
	h.resize(m);
	lSum.resize(m + 1);
	hSum.resize(m + 1);
	pSum.resize(m + 1);
	for (int i = 0; i < m; ++i)
	{
		fin >> l[i] >> h[i];
		lSum[i + 1] = lSum[i] + l[i];
		hSum[i + 1] = hSum[i] + h[i];
		pSum[i + 1] = pSum[i] + l[i] * hSum[i + 1];
	}
	res.resize(m, vector<int>(m - n + 1, INF));
	fout << ans(0, m - n);

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}