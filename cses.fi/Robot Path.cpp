#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long X = 0, Y = 0;
vector<long long> xtrue, ytrue;
vector<set<pair<long long, long long>>> xline, yline;
vector<vector<long long>> xadd, yadd;
long long x, y, res = 0;

void changey(long long v, long long l, long long r, long long L, long long R, long long x);
//XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
void pushx(long long v)
{
	xadd[v * 2 + 1].insert(xadd[v * 2 + 1].end(), xadd[v].begin(), xadd[v].end());
	xadd[v * 2 + 2].insert(xadd[v * 2 + 2].end(), xadd[v].begin(), xadd[v].end());
	xadd[v].clear();
}

void fixx(long long v, long long l, long long r, long long x)
{
	if (x < l || r <= x) return;
	if (l + 1 == r)
	{
		for (auto& i : xadd[v])
			xline[x].emplace(i, i);
		xadd[v].clear();
		return;
	}
	long long m = (l + r) / 2;
	pushx(v);
	fixx(v * 2 + 1, l, m, x);
	fixx(v * 2 + 2, m, r, x);
}

void changex(long long v, long long l, long long r, long long L, long long R, long long y)
{
	if (r <= L || R <= l) return;
	if (L <= l && r <= R)
	{
		xadd[v].push_back(y);
		return;
	}
	long long m = (l + r) / 2;
	changex(v * 2 + 1, l, m, L, R, y);
	changex(v * 2 + 2, m, r, L, R, y);
}

long long findminx(long long x, long long l, long long r)
{
	fixx(0, 0, X, x);
	auto& line = xline[x];
	auto it = line.lower_bound({ l, l });
	if (it != line.begin() && prev(it)->second >= l) return l;
	if (it != line.end() && it->first <= r) return it->first;
	return -1;
}

long long findmaxx(long long x, long long l, long long r)
{
	fixx(0, 0, X, x);
	auto& line = xline[x];
	auto it = line.upper_bound({ r, 1e18 });
	if (it != line.begin() && prev(it)->first >= l) return min(r, prev(it)->second);
	return -1;
}

bool R(long long d)
{
	long long h = findminx(x, y + 1, y + d);
	if (h == -1)
	{
		xline[x].emplace(y + 1, y + d);
		changey(0, 0, Y, y + 1, y + d + 1, x);
		res += ytrue[y + d] - ytrue[y];
		y += d;
		return true;
	}
	res += ytrue[h] - ytrue[y];
	return false;
}

bool L(long long d)
{
	long long h = findmaxx(x, y - d, y - 1);
	if (h == -1)
	{
		xline[x].emplace(y - d, y - 1);
		changey(0, 0, Y, y - d, y - 1 + 1, x);
		res += ytrue[y] - ytrue[y - d];
		y -= d;
		return true;
	}
	res += ytrue[y] - ytrue[h];
	return false;
}

//YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY
void pushy(long long v)
{
	yadd[v * 2 + 1].insert(yadd[v * 2 + 1].end(), yadd[v].begin(), yadd[v].end());
	yadd[v * 2 + 2].insert(yadd[v * 2 + 2].end(), yadd[v].begin(), yadd[v].end());
	yadd[v].clear();
}

void fixy(long long v, long long l, long long r, long long y)
{
	if (y < l || r <= y) return;
	if (l + 1 == r)
	{
		for (auto& i : yadd[v])
			yline[y].emplace(i, i);
		yadd[v].clear();
		return;
	}
	long long m = (l + r) / 2;
	pushy(v);
	fixy(v * 2 + 1, l, m, y);
	fixy(v * 2 + 2, m, r, y);
}

void changey(long long v, long long l, long long r, long long L, long long R, long long x)
{
	if (r <= L || R <= l) return;
	if (L <= l && r <= R)
	{
		yadd[v].push_back(x);
		return;
	}
	long long m = (l + r) / 2;
	changey(v * 2 + 1, l, m, L, R, x);
	changey(v * 2 + 2, m, r, L, R, x);
}

long long findminy(long long y, long long l, long long r)
{
	fixy(0, 0, Y, y);
	auto& line = yline[y];
	auto it = line.lower_bound({ l, l });
	if (it != line.begin() && prev(it)->second >= l) return l;
	if (it != line.end() && it->first <= r) return it->first;
	return -1;
}

long long findmaxy(long long y, long long l, long long r)
{
	fixy(0, 0, Y, y);
	auto& line = yline[y];
	auto it = line.upper_bound({ r, 1e18 });
	if (it != line.begin() && prev(it)->first >= l) return min(r, prev(it)->second);
	return -1;
}

bool D(long long d)
{
	long long h = findminy(y, x + 1, x + d);
	if (h == -1)
	{
		yline[y].emplace(x + 1, x + d);
		changex(0, 0, X, x + 1, x + d + 1, y);
		res += xtrue[x + d] - xtrue[x];
		x += d;
		return true;
	}
	res += xtrue[h] - xtrue[x];
	return false;
}

bool U(long long d)
{
	long long h = findmaxy(y, x - d, x - 1);
	if (h == -1)
	{
		yline[y].emplace(x - d, x - 1);
		changex(0, 0, X, x - d, x - 1 + 1, y);
		res += xtrue[x] - xtrue[x - d];
		x -= d;
		return true;
	}
	res += xtrue[x] - xtrue[h];
	return false;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n; cin >> n;
	vector<pair<long long, long long>> coord(n + 1); coord[0] = { 0, 0 };
	for (long long i = 1; i <= n; ++i)
	{
		coord[i] = coord[i - 1];
		char h; long long d; cin >> h >> d;
		if (h == 'U')
			coord[i].first -= d;
		if (h == 'L')
			coord[i].second -= d;
		if (h == 'D')
			coord[i].first += d;
		if (h == 'R')
			coord[i].second += d;
	}
	vector<long long> ord(n + 1); iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](long long a, long long b) {
		return coord[a].first < coord[b].first; 
	});
	long long prevx = -1e18;
	for (auto& i : ord)
	{
		if (coord[i].first > prevx)
		{
			prevx = coord[i].first;
			xtrue.push_back(prevx);
			++X;
		}
		coord[i].first = X - 1;
	}
	sort(ord.begin(), ord.end(), [&](long long a, long long b) {
		return coord[a].second < coord[b].second;
	});
	long long prevy = -1e18;
	for (auto& i : ord)
	{
		if (coord[i].second > prevy)
		{
			prevy = coord[i].second;
			ytrue.push_back(prevy);
			++Y;
		}
		coord[i].second = Y - 1;
	}

	x = coord[0].first, y = coord[0].second;
	xline.resize(X); xadd.resize(X * 4);
	xline[x].emplace(y, y);
	yline.resize(Y); yadd.resize(Y * 4);
	yline[y].emplace(x, x);
	char was = 'n';
	for (long long i = 1; i <= n; ++i)
	{
		long long dx = coord[i].first - x, dy = coord[i].second - y;
		if (dx < 0)
		{
			if (was == 'D') break;
			if (!U(abs(dx)))
				break;
			was = 'U';
		}
		if (dy < 0)
		{
			if (was == 'R') break;
			if (!L(abs(dy)))
				break;
			was = 'L';
		}
		if (dx > 0)
		{
			if (was == 'U') break;
			if (!D(abs(dx)))
				break;
			was = 'D';
		}
		if (dy > 0)
		{
			if (was == 'L') break;
			if (!R(abs(dy)))
				break;
			was = 'R';
		}
	}
	cout << res << '\n';

	return 0;
}