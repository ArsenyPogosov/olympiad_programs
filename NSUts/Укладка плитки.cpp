#include <fstream>
#include <vector>
//#include <queue>
//#include <list>
#include <map>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

vector<vector<bool>> flore;
map<pair<int, int>, int> ans;

int n, k, p = 1000000000+7;

int Answer(int l1, int l2)
{
	while ((l1 != n) && (flore[0][l1])) ++l1;
	while ((l2 != n) && (flore[1][l2])) ++l2;

	if (ans.find(pair<int, int>(l1, l2)) != ans.end())
		return ans[pair<int, int>(l1, l2)];

	if ((l1 >= n) && (l2 >= n)) return 1;

	int res = 0;
	if (l1 <= l2)
	{
		res = (res + Answer(l1 + 1, l2)) % p;
		if ((l1 + 1 < n)&&(!flore[0][l1+1]))
			res = (res + Answer(l1 + 2, l2)) % p;
	}
	if (l2 < l1)
	{
		res = (res + Answer(l1, l2 + 1)) % p;
		if ((l2 + 1 < n) && (!flore[1][l2 + 1]))
			res = (res + Answer(l1, l2 + 2)) % p;
	}
	if (l1 == l2)
	{
		res = (res + Answer(l1 + 1, l2 + 1)) % p;
	}

	ans.insert(pair<pair<int, int>, int>(pair<int, int>(l1, l2), res));
	return res;
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	fin >> n >> k;
	flore.resize(2, vector<bool>(n, false));
	for (int i = 0; i < k; ++i)
	{
		int x, y;
		fin >> x >> y;
		flore[y - 1][x - 1] = true;
	}

	fout << Answer(0, 0);

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}