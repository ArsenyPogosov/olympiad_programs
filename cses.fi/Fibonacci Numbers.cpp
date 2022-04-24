#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long p = 1e9 + 7;

vector<vector<long long>> mult(vector<vector<long long>> a, vector<vector<long long>> b)
{
	vector<vector<long long>> res(2, vector<long long>(2, 0));
	for (long long i = 0; i < 2; ++i)
		for (long long j = 0; j < 2; ++j)
		{
			for (long long k = 0; k < 2; ++k)
				res[i][j] += a[i][k] * b[k][j];
			res[i][j] %= p;
		}
	return res;
}

vector<vector<long long>> ppow(vector<vector<long long>> a, long long k)
{
	if (k == 0) return { {1, 0}, {0, 1} };
	if (k % 2 == 0)
	{
		vector<vector<long long>> res = ppow(a, k / 2);
		return mult(res, res);
	}
	return mult(ppow(a, k - 1), a);
}

long long fib(long long n)
{
	return ppow({ {1, 1}, {1, 0} }, n)[0][1];
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n; cin >> n;
	cout << fib(n) << '\n';

	return 0;
}