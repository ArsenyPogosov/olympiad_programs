#include <fstream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
#include <string>
using namespace std;

struct node 
{
	long long hash;
	int newValue;
};

vector<long long> P(100010);
vector<long long> PprefSum(100010);

vector<int> color;
vector<node> tree;

void PInit()
{
	P[0] = 1; P[1] = 1610612741;
	for (int i = 2; i < P.size(); ++i) P[i] = P[i - 1] * P[1];
	PprefSum[0] = P[0];
	for (int i = 1; i < PprefSum.size(); ++i) PprefSum[i] = PprefSum[i - 1] + P[i];
}

long long combineHash(long long h1, int l1, long long h2, int l2)
{
	return h1 + h2*P[l1];
}

void build(int v, int lV, int rV)
{
	if (lV == rV) { tree[v].hash = color[lV]; return; }

	int m = (lV + rV) / 2;
	build(v * 2, lV, m);
	build(v * 2 + 1, m + 1, rV);
	tree[v].hash = combineHash(tree[v * 2].hash, m - lV + 1, tree[v * 2 + 1].hash, rV - m);
}

void pushUpdate(int v, int lV, int rV)
{
	if (tree[v].newValue == -1) return;

	int m = (lV + rV) / 2;
	tree[v * 2].hash = tree[v].newValue*PprefSum[m - lV];
	tree[v * 2 + 1].hash = tree[v].newValue*PprefSum[rV - m - 1];
	tree[v * 2].newValue = tree[v].newValue; 
	tree[v * 2 + 1].newValue = tree[v].newValue;
	tree[v].newValue = -1;
}

void Update(int v, int lV, int rV, int l, int r, int newValue)
{
	if (r < lV || rV < l) return;
	if (l <= lV && rV <= r)
	{
		tree[v].hash = newValue*PprefSum[rV - lV];
		tree[v].newValue = newValue;
		return;
	}

	pushUpdate(v, lV, rV);
	int m = (lV + rV) / 2;
	Update(v * 2, lV, m, l, r, newValue);
	Update(v * 2 + 1, m + 1, rV, l, r, newValue);
	tree[v].hash = combineHash(tree[v * 2].hash, m - lV + 1, tree[v * 2 + 1].hash, rV - m - 1 + 1);
}

long long HashInTree(int v, int lV, int rV, int l, int r)
{
	if (r < lV || rV < l) return 0;
	if (l <= lV && rV <= r) return tree[v].hash;

	pushUpdate(v, lV, rV);
	int m = (lV + rV) / 2;
	long long hash1 = HashInTree(v * 2, lV, m, l, r), hash2 = HashInTree(v * 2 + 1, m + 1, rV, l, r);
	return combineHash(hash1, max(min(r, m) - max(l, lV) + 1, 0), hash2, max(min(r, rV) - max(l, m + 1) + 1, 0));
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	PInit();

	int n; fin >> n;
	color = vector<int>(n);
	for (auto&i : color) fin >> i;
	tree = vector<node>(4 * n + 2, {0, -1});
	build(1, 0, n - 1);

	int m, q, l, r, k; fin >> m;
	for (int i = 0; i <= m - 1; ++i)
	{
		fin >> q >> l >> r >> k; --l; --r;
		if (q == 0) Update(1, 0, n - 1, l, r, k);
		if (q == 1)
		{
			if (HashInTree(1, 0, n - 1, l, l + k - 1) == HashInTree(1, 0, n - 1, r, r + k - 1))
				fout << '+';
			else
				fout << '-';
		}
	}

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}