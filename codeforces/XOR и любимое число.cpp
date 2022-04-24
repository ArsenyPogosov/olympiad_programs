//source: https://olympsirius.contest.codeforces.com/group/vQvyd7suOa/contest/258598/problem/C_easy
//status: coding

#include <bits/stdc++.h>
#include <unordered_map>
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

long long n, m, k;
vector<long long> mass;

const long long C = 500;

struct query
{
	long long ind, l, r;
	query() {};
	query(long long _ind, long long _l, long long _r) { ind = _ind; l = _l; r = _r; };
};

vector<query> Q;

long long L = 0, R = 0, cnt = 0, pl = 0, pr = 0;
unordered_map<long long, long long> cp;

void move(long long l, long long r)
{
	while (l < L)
	{
		--L;
		++cp[pl];
		pl ^= mass[L];
		auto it = cp.find(k ^ pl);
		if (it != cp.end()) cnt += it->second;
	}
	while (R < r)
	{
		pr ^= mass[R];
		auto it = cp.find(k ^ pr);
		if (it != cp.end()) cnt += it->second;
		if (pl == (k ^ pr)) ++cnt;
		++cp[pr];
		++R;
	}
	while (L < l)
	{
		auto it = cp.find(k ^ pl);
		if (it != cp.end()) cnt -= it->second;
		pl ^= mass[L];
		auto xxx = cp.find(pl);
		--xxx->second;
		if (xxx->second == 0) cp.erase(xxx);
		++L;
	}
	while (r < R)
	{
		--R;
		auto it = cp.find(pr);
		--it->second;
		if (it->second == 0) cp.erase(it);
		auto xxx = cp.find(k ^ pr);
		if (xxx != cp.end()) cnt -= xxx->second;
		if (pl == (k ^ pr)) --cnt;
		pr ^= mass[R];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k; 
	mass.resize(n); for (auto& i : mass) cin >> i;
	Q.resize(m);
	for (long long i = 0; i < m; ++i)
	{
		long long l, r; cin >> l >> r;
		Q[i] = query(i, l - 1, r);
	}
	sort(Q.begin(), Q.end(), [&](query a, query b) {
		if (a.l / C != b.l / C) return a.l < b.l;
		return a.r < b.r;
		});
	vector<long long> ans(m);
	for (auto& i : Q)
	{
		move(i.l, i.r);
		ans[i.ind] = cnt;
	}
	for (auto& i : ans) cout << i << '\n';

	return 0;
}