#include <fstream>
#include <vector>
//#include <queue-max>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
//#include <string>
using namespace std;

vector<long long> S, D, tree;

long long SumK(long long i, long long k)
{
	if (i > 0)
		return S[i + k - 1] - S[i - 1];

	return S[i + k - 1];
}

void Init(long long v, long long l, long long r)
{
	if (l == r)
	{
		tree[v] = D[l];
		return;
	}

	Init(v * 2, l, (l + r) / 2);
	Init(v * 2 + 1, (l + r) / 2 + 1, r);
	tree[v] = max(tree[v * 2], tree[v * 2 + 1]);
}

long long MaxInTree(long long v, long long lv, long long rv, long long l, long long r)
{
	if ((l <= lv) && (rv <= r))
	{
		return tree[v];
	}
	if ((rv < l) || (r < lv))
	{
		return -1;
	}

	return(max(MaxInTree(v * 2, lv, (lv + rv) / 2, l, r),
		MaxInTree(v * 2 + 1, (lv + rv) / 2 + 1, rv, l, r)));
}

int main()
{
	ifstream fin("input.txt");	 //open input file
	ofstream fout("output.txt"); //open output file

	long long n, k;
	fin >> n >> k;
	vector<long long> N(n); S.resize(n); D.resize(n - k + 1), tree.resize(n * 4 + 10);
	for (auto&i : N)
		fin >> i;
	S[0] = N[0];
	for (long long i = 1; i < n; ++i)
		S[i] = S[i - 1] + N[i];
	for (long long i = 0; i < n - k + 1; ++i)
		D[i] = SumK(i, k);

	Init(1, 0, n - k);
	long long ans = 1000000000000000000;
	for (int i = 0; i <= n - k; ++i)
	{
		ans = min(ans, max(MaxInTree(1, 0, n - k, 0, i - k), MaxInTree(1, 0, n - k, i + k, n - 1)));
	}
	fout << ans;

	fin.close();  //close input file
	fout.close(); //close output file

	return 0;
}