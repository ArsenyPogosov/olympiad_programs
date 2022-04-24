#include <iostream>
#include <vector>
//#include <queue>
//#include <list>
//#include <map>
#include <algorithm>
#include <cmath>
//#include <string>
using namespace std;

long long k;
vector<long long> a, clen;
vector<pair<long long, long long>> query;
long long l = 0, r = 0;
long long tekRes = 0;

bool comp(const long long& a, const long long& b)
{
	if (query[a].first / k != query[b].first / k)
		return query[a].first < query[b].first;
	return query[a].second < query[b].second;
}

long long power(long long x)
{
	return clen[a[x]] * clen[a[x]] * a[x];
}

void add(long long x)
{
	tekRes -= power(x);
	clen[a[x]] += 1;
	tekRes += power(x);
}

void remove(long long x)
{
	tekRes -= power(x);
	clen[a[x]] -= 1;
	tekRes += power(x);
}

long long NextRes(long long nl, long long nr)
{
	while (nl < l)
		add(--l);
	while (r < nr)
		add(++r);
	while (nl > l)
		remove(l++);
	while (r > nr)
		remove(r--);

	return tekRes;
}

int main()
{
	long long n, m;
	cin >> n >> m;
	k = sqrt(n);
	a.resize(n);
	for (auto&i : a)
		cin >> i;
	query.resize(m);
	for (auto&i : query)
	{
		cin >> i.first >> i.second;
		--i.first;
		--i.second;
	}
	vector<long long> sq(m), res(m);
	for (long long i = 0; i < m; ++i)
		sq[i] = i;
	sort(sq.begin(), sq.end(), comp);
	clen.resize(1000001);
	clen[a[0]] += 1;
	tekRes = power(0);
	for (auto&i : sq)
		res[i] = NextRes(query[i].first, query[i].second);
	for (auto&i : res)
		cout << i << '\n';

	return 0;
}