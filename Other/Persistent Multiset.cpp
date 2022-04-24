#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<vector<pair<int, int>>> cnt;
vector<pair<int, int>> diff, uniqu;

void add(int x, int v)
{
	diff.emplace_back(v, diff.back().second);
	uniqu.emplace_back(v, uniqu.back().second);

	if (cnt[x].back().second > 0) --diff.back().second;
	if (cnt[x].back().second == 1) --uniqu.back().second;

	cnt[x].emplace_back(v, cnt[x].back().second + 1);

	if (cnt[x].back().second > 0) ++diff.back().second;
	if (cnt[x].back().second == 1) ++uniqu.back().second;
}

void del(int x, int v)
{
	diff.emplace_back(v, diff.back().second);
	uniqu.emplace_back(v, uniqu.back().second);

	if (cnt[x].back().second > 0) --diff.back().second;
	if (cnt[x].back().second == 1) --uniqu.back().second;

	cnt[x].emplace_back(v, max(0, cnt[x].back().second - 1));

	if (cnt[x].back().second > 0) ++diff.back().second;
	if (cnt[x].back().second == 1) ++uniqu.back().second;
}

int get(const vector<pair<int, int>>& mass, int v)
{
	return (--lower_bound(mass.begin(), mass.end(), pair<int, int>{ v + 1, 0 }))->second;
}

int different(int v)
{
	return get(diff, v);
}

int unique(int v)
{
	return get(uniqu, v);
}

int count(int x, int v)
{
	return get(cnt[x], v);
}


int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n, m; cin >> n >> m; ++m;
	cnt.resize(m, { { 0, 0 } });
	diff = uniqu = { {0, 0} };

	long long sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		string s; cin >> s;
		if (s == "add")
		{
			int x; cin >> x;
			add(x, i);
		}
		if (s == "remove")
		{
			int x; cin >> x;
			del(x, i);
		}
		if (s == "different")
		{
			int v; cin >> v;
			int res = different((v + sum) % i);
			sum += res;
			cout << res << '\n';
		}
		if (s == "unique")
		{
			int v; cin >> v;
			int res = unique((v + sum) % i);
			sum += res;
			cout << res << '\n';
		}
		if (s == "count")
		{
			int x, v; cin >> x >> v;
			int res = count(x, (v + sum) % i);
			sum += res;
			cout << res << '\n';
		}
	}

	return 0;
}