#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long p = 1e9 + 7;

typedef vector<vector<long long>> matrix;

matrix mult(matrix a, matrix b)
{
	long long an = a.size(), am = a[0].size(), bn = b.size(), bm = b[0].size();
	if (am != bn)
		cout << "end of the world! (sono chi no kioku)\n";
	matrix res(an, vector<long long>(bm, 0));
	for (long long i = 0; i < an; ++i)
		for (long long j = 0; j < bm; ++j)
			for (long long k = 0; k < am; ++k)
			{
				res[i][j] += a[i][k] * b[k][j];
				res[i][j] %= p;
			}
	return res;
}

matrix ppow(matrix a, long long k)
{
	if (k == 0)
	{
		long long n = a.size();
		matrix res(n, vector<long long>(n));
		for (long long i = 0; i < n; ++i)
			res[i][i] = 1;
		return res;
	}
	if (k % 2 == 0)
	{
		matrix res = ppow(a, k / 2);
		return mult(res, res);
	}
	return mult(ppow(a, k - 1), a);
}

long long knachi(long long n, long long k)
{
	matrix nxt(k, vector<long long>(k)), res(k, vector<long long>(1));
	for (auto& i : nxt[0]) i = 1;
	for (long long i = 1; i < k; ++i) nxt[i][i - 1] = 1;
	res[0][0] = 1;
	return mult(ppow(nxt, n), res)[1][0];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n; cin >> n;
	cout << knachi(n + 1, 6) << '\n';

	return 0;
}