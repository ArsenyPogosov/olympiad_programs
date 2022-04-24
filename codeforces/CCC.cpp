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

int N, M;
vector<vector<int>> mass, psum;

int Sum(int l, int r)
{
	return (l >= 0 && r >= 0 ? psum[l][r] : 0);
}

int Sum(int l1, int r1, int l2, int r2)
{
	return Sum(l2, r2) - Sum(l1 - 1, r2) - Sum(l2, r1 - 1) + Sum(l1 - 1, r1 - 1);
}

bool ok(int l1, int r1, int l2, int r2)
{
	return (Sum(l1, r1, l2, r2) == (l2 - l1 + 1) * (r2 - r1 + 1));
}

void build()
{
	psum.resize(N, vector<int>(M));
	partial_sum(mass[0].begin(), mass[0].end(), psum[0].begin());
	for (int i = 1; i < N; ++i)
	{
		psum[i][0] = psum[i - 1][0] + mass[i][0];
		for (int j = 1; j < M; ++j)
			psum[i][j] = mass[i][j] + psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];
	}
}

int main()
{
	cin >> N >> M;
	mass.resize(N, vector<int>(M, 0));
	for (auto&i: mass)
		for (auto& j : i)
		{
			char h; cin >> h;
			if (h == '#') j = 1;
		}
	build();
	int l = 1, r = max(N, M) + 2;
	while (l + 1 < r)
	{
		int m = (l + r) / 2;
		bool flag = false;
		for (int i = m; (i + 2 * m <= N) && (!flag); ++i)
			for (int j = m; j + 2 * m <= M; ++j)
			{
				if (!ok(i, j, i + m - 1, j + m - 1)) continue;
				if (!ok(i - m, j, i - 1, j + m - 1)) continue;
				if (!ok(i + m, j, i + m * 2 - 1, j + m - 1)) continue;
				if (!ok(i, j - m, i + m - 1, j - 1)) continue;
				if (!ok(i, j + m, i + m - 1, j + m * 2 - 1)) continue;
				flag = true; break;
			}
		if (flag)
			l = m;
		else
			r = m;
	}
	cout << l;

	return 0;
}