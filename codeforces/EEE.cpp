//source: http://neerc.ifmo.ru/school/sirius-2019/problems/20191111.pdf
//status: coding

#include <bits/stdc++.h>
using namespace std;
//#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif
#pragma endregion

int n;
vector<int> mass, psum;

int Sum(int l, int r)
{
	return psum[r] - (l > 0 ? psum[l - 1] : 0);
}

bool ok(int l, int r)
{
	return (Sum(l, r) == r - l + 1);
}

int main()
{
	cin >> n;
	mass.resize(n);
	psum.resize(n);
	for (auto& i : mass) { char h; cin >> h; i = h - '0'; }
	partial_sum(mass.begin(), mass.end(), psum.begin());
	int m, a, b;
	cin >> m >> a >> b;
	int count = 0;
	for (int i = 0; i < a + b; ++i)
	{ 
		int f = i;
		while (f <= n - (a + b) * m)
		{
			int nb = 0, lb = f, rb = lb + a + b - 1;
			while (rb < n)
			{
				if (ok(lb, lb + a - 1))
				{
					if (nb + 1 >= m) ++count;
					++nb;
					lb += a + b;
					rb += a + b;
				}
				else
				{
					break;
				}
			}
			f = rb + 1;
		}
	}
	cout << count;

	return 0;
}