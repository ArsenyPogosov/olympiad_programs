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

int combine(int v1, int v2)
{
	if (arr[tree[v1]] >= arr[tree[v2]])
		return tree[v1];
	return tree[v2];
}

void build(int v, int lV, int rV)
{
	if (lV == rV)
	{
		tree[v] = lV;
		return;
	}
	int m = (lV + rV) / 2;
	build(2 * v, lV, m);
	build(2 * v + 1, m + 1, rV);
	tree[v] = combine(2 * v, 2 * v + 1);
}

int LeftMax(int v, int lV, int rV, int l, int r)
{
	if (r < lV || rV < l) return -1;
	if (l <= lV && rV <= r) return tree[v];
	int m = (lV + rV) / 2;

	int max1 = LeftMax(2 * v, lV, m, l, r);
	int max2 = LeftMax(2 * v + 1, m + 1, rV, l, r);
	if (max1 == -1 && max2 == -1) return -1;
	if (max1 == -1) return max2;
	if (max2 == -1) return max1;
	if (arr[max1] >= arr[max2])
		return max1;
	return max2;
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n;
	fin >> n;
	arr = vector<int>(n);
	for (auto&i : arr) fin >> i;
	tree = vector<int>(n*4 + 1);
	build(1, 0, n - 1);
	int k;
	fin >> k;
	int l, r;
	for (int i = 0; i <= k - 1; ++i)
	{
		fin >> l >> r; --l; --r;
		fout << LeftMax(1, 0, n - 1, l, r) + 1 << ' ';
	}

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}