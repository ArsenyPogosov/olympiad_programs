//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/258672/problems
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

const long long P = 1000000007;

long long n, m, I;
vector<long long> LOG2(1000 + 1);
vector<vector<long long>> X1, X2, Y1, Y2;
vector<vector<vector<vector<long long>>>> STX1, STX2, STY1, STY2;

void build()
{
	long long teki = 0, tekp = 1;
	for (long long i = 1; i <= max(n, m) + 1; ++i)
	{
		if (tekp * 2 <= i) { tekp *= 2; ++teki; }
		LOG2[i] = teki;
	}
	I = LOG2[max(n, m)] + 1;

	STX1.resize(I, vector<vector<vector<long long>>>(I, vector<vector<long long>>(n, vector<long long>(m))));
	STY2 = STY1 = STX2 = STX1;

	for (long long k = 0; k < n; ++k)
		copy(X1[k].begin(), X1[k].end(), STX1[0][0][k].begin());
	for (long long i = 1; i < I; ++i)
		for (long long k = 0; k < n; ++k)
			for (long long l = 0; l < m; ++l)
				STX1[i][0][k][l] = max(STX1[i - 1][0][k][l], STX1[i - 1][0][min(n - 1, k + (1 << (i - 1)))][l]);
	for (long long i = 0; i < I; ++i)
		for (long long j = 1; j < I; ++j)
			for (long long k = 0; k < n; ++k)
				for (long long l = 0; l < m; ++l)
					STX1[i][j][k][l] = max(STX1[i][j - 1][k][l], STX1[i][j - 1][k][min(m - 1, l + (1 << (j - 1)))]);

	for (long long k = 0; k < n; ++k)
		copy(X2[k].begin(), X2[k].end(), STX2[0][0][k].begin());
	for (long long i = 1; i < I; ++i)
		for (long long k = 0; k < n; ++k)
			for (long long l = 0; l < m; ++l)
				STX2[i][0][k][l] = min(STX2[i - 1][0][k][l], STX2[i - 1][0][min(n - 1, k + (1 << (i - 1)))][l]);
	for (long long i = 0; i < I; ++i)
		for (long long j = 1; j < I; ++j)
			for (long long k = 0; k < n; ++k)
				for (long long l = 0; l < m; ++l)
					STX2[i][j][k][l] = min(STX2[i][j - 1][k][l], STX2[i][j - 1][k][min(m - 1, l + (1 << (j - 1)))]);

	for (long long k = 0; k < n; ++k)
		copy(Y1[k].begin(), Y1[k].end(), STY1[0][0][k].begin());
	for (long long i = 1; i < I; ++i)
		for (long long k = 0; k < n; ++k)
			for (long long l = 0; l < m; ++l)
				STY1[i][0][k][l] = max(STY1[i - 1][0][k][l], STY1[i - 1][0][min(n - 1, k + (1 << (i - 1)))][l]);
	for (long long i = 0; i < I; ++i)
		for (long long j = 1; j < I; ++j)
			for (long long k = 0; k < n; ++k)
				for (long long l = 0; l < m; ++l)
					STY1[i][j][k][l] = max(STY1[i][j - 1][k][l], STY1[i][j - 1][k][min(m - 1, l + (1 << (j - 1)))]);

	for (long long k = 0; k < n; ++k)
		copy(Y2[k].begin(), Y2[k].end(), STY2[0][0][k].begin());
	for (long long i = 1; i < I; ++i)
		for (long long k = 0; k < n; ++k)
			for (long long l = 0; l < m; ++l)
				STY2[i][0][k][l] = min(STY2[i - 1][0][k][l], STY2[i - 1][0][min(n - 1, k + (1 << (i - 1)))][l]);
	for (long long i = 0; i < I; ++i)
		for (long long j = 1; j < I; ++j)
			for (long long k = 0; k < n; ++k)
				for (long long l = 0; l < m; ++l)
					STY2[i][j][k][l] = min(STY2[i][j - 1][k][l], STY2[i][j - 1][k][min(m - 1, l + (1 << (j - 1)))]);

}

long long MaxX1(long long l1, long long r1, long long l2, long long r2)
{
	long long mil = LOG2[l2 - l1 + 1], mir = LOG2[r2 - r1 + 1];
	return max({ STX1[mil][mir][l1][r1], STX1[mil][mir][l2 - (1 << mil) + 1][r1], STX1[mil][mir][l1][r2 - (1 << mir) + 1], STX1[mil][mir][l2 - (1 << mil) + 1][r2 - (1 << mir) + 1] });
}

long long MaxY1(long long l1, long long r1, long long l2, long long r2)
{
	long long mil = LOG2[l2 - l1 + 1], mir = LOG2[r2 - r1 + 1];
	return max({ STY1[mil][mir][l1][r1], STY1[mil][mir][l2 - (1 << mil) + 1][r1], STY1[mil][mir][l1][r2 - (1 << mir) + 1], STY1[mil][mir][l2 - (1 << mil) + 1][r2 - (1 << mir) + 1] });
}

long long MinX2(long long l1, long long r1, long long l2, long long r2)
{
	long long mil = LOG2[l2 - l1 + 1], mir = LOG2[r2 - r1 + 1];
	return min({ STX2[mil][mir][l1][r1], STX2[mil][mir][l2 - (1 << mil) + 1][r1], STX2[mil][mir][l1][r2 - (1 << mir) + 1], STX2[mil][mir][l2 - (1 << mil) + 1][r2 - (1 << mir) + 1] });
}

long long MinY2(long long l1, long long r1, long long l2, long long r2)
{
	long long mil = LOG2[l2 - l1 + 1], mir = LOG2[r2 - r1 + 1];
	return min({ STY2[mil][mir][l1][r1], STY2[mil][mir][l2 - (1 << mil) + 1][r1], STY2[mil][mir][l1][r2 - (1 << mir) + 1], STY2[mil][mir][l2 - (1 << mil) + 1][r2 - (1 << mir) + 1] });
}

long long query(long long l1, long long r1, long long l2, long long r2)
{
	if (l2 < l1) swap(l2, l1);
	if (r2 < r1) swap(r2, r1);
	if (MinX2(l1, r1, l2, r2) - MaxX1(l1, r1, l2, r2) < 0) return 0;
	if (MinY2(l1, r1, l2, r2) - MaxY1(l1, r1, l2, r2) < 0) return 0;
	return (MinX2(l1, r1, l2, r2) - MaxX1(l1, r1, l2, r2)) * (MinY2(l1, r1, l2, r2) - MaxY1(l1, r1, l2, r2));
}

int main()
{
	cin >> n >> m;
	X1.resize(n, vector<long long>(m));
	Y1.resize(n, vector<long long>(m));
	X2.resize(n, vector<long long>(m));
	Y2.resize(n, vector<long long>(m));
	for (long long i = 0; i < n; ++i)
		for (long long j = 0; j < m; ++j)
		{
			cin >> X1[i][j] >> Y1[i][j] >> X2[i][j] >> Y2[i][j];
			if (X1[i][j] > X2[i][j]) swap(X1[i][j], X2[i][j]);
			if (Y1[i][j] > Y2[i][j]) swap(Y1[i][j], Y2[i][j]);
		}
	build();

	/*for (long long i1 = 0; i1 < n; ++i1)
		for (long long j1 = 0; j1 < m; ++j1)
			for (long long i2 = i1; i2 < n; ++i2)
				for (long long j2 = j1; j2 < m; ++j2)
				{
					long long ans1 = MaxX1(i1, j1, i2, j2);
					long long ans2 = -1;
					for (long long i = i1; i <= i2; ++i)
						for (long long j = j1; j <= j2; ++j)
							ans2 = max(ans2, X1[i][j]);
					if (ans1 != ans2)
					{
						cout << i1 << ' ' << j1 << ' ' << i2 << ' ' << j2 << ' ' << ans1 << ' ' << ans2 << '\n';
					}
				}*/

	long long Q, A, B, v0; cin >> Q >> A >> B >> v0;
	vector<long long> v(Q * 4 + 10); v[0] = v0;
	for (long long i = 1; i < Q * 4 + 5; ++i) v[i] = (A * v[i - 1] + B) % P;
	long long res = 0;
	for (long long i = 1; i <= Q; ++i)
		res = (res + query(v[4 * i - 3] % n, v[4 * i - 2] % m, v[4 * i - 1] % n, v[4 * i - 0] % m)) % P;
	cout << res;

	return 0;
}