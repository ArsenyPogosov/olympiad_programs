#include <fstream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

int Nearest(int n)
{
	int res{ 1 };
	while (res < n) res *= 2;

	return res;
}

vector<int> tree;
vector<int> mass;

int MaxInTree(int x, int l, int r, int a, int b)
{
	if ((r < a) || (b < l)) return 0;
	if ((a <= l) && (r <= b)) return tree[x];
	
	int ans1{ MaxInTree(x * 2, l, (l + r) / 2, a, b) },
		ans2{ MaxInTree(x * 2 + 1, (l + r) / 2 + 1, r, a, b) };
	if (mass[ans1] >= mass[ans2])
		return ans1;
	return ans2;
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	int n;
	fin >> n;
	mass.resize(Nearest(n) + 1); mass[0] = -1000000;
	for (int i = 1; i <= n; ++i) fin >> mass[i];
	for (int i = n + 1; i <= mass.size() - 1; ++i) 
		mass[i] = -1000000;
	n = mass.size() - 1;

	tree.resize(n * 2 + 1);
	for (int i = 1; i <= n; ++i)
		tree[n + i - 1] = i;
	for (int i = n - 1; i > 0; --i)
		if (mass[tree[i * 2]] >= mass[tree[i * 2 + 1]])
			tree[i] = tree[i * 2];
		else
			tree[i] = tree[i * 2 + 1];

	int k; fin >> k;
	for (int i = 0; i < k; ++i)
	{
		int a, b; fin >> a >> b;
		fout << MaxInTree(1, 1, n, a, b) << ' ';
	}

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}