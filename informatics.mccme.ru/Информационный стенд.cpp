#include <fstream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
//#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

vector<int> tree;
vector<int> arr;

void build(int v, int lV, int rV)
{
	tree[v] = lV;
	if (lV == rV) return;
	int m = (lV + rV) / 2;
	build(v * 2, lV, m);
	build(v * 2 + 1, m + 1, rV);
}

int hang(int v, int lV, int rV, int x)
{
	if (arr[tree[v]] < x) return -2;
	if (lV == rV)
	{
		arr[tree[v]] -= x;
		return lV;
	}

	int res;
	int m = (lV + rV) / 2;
	if (arr[tree[v * 2]] >= x)
		res = hang(v * 2, lV, m, x);
	else
		res = hang(v * 2 + 1, m + 1, rV, x);

	if (arr[tree[v * 2]] >= arr[tree[v * 2 + 1]])
		tree[v] = tree[v * 2];
	else
		tree[v] = tree[v * 2 + 1];

	return res;
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int h, w, n;
	fin >> h >> w >> n;
	tree = vector<int>(n * 4);
	build(1, 0, n - 1);
	arr = vector<int>(n, w);
	int x, ans;
	for (int i = 0; i <= n - 1; ++i)
	{
		fin >> x;
		ans = hang(1, 0, n - 1, x) + 1;
		if (ans <= h)
			fout << ans << '\n';
		else
			fout << "-1\n";
	}

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}