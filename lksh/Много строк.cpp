#include <iostream>
#include <vector>
#include <map>
//#include <list>
//#include <map>
#include <algorithm>
//#include <math>
#include <string>
using namespace std;

const long long b = 31;
const long long p = 1000000007;

vector<long long> bpow;

void InitBpow(long long n = 100001)
{
	bpow.resize(n);
	bpow[0] = 1;
	for (long long i = 1; i < n; ++i)
		bpow[i] = bpow[i - 1] * b % p;
}

void InintHashPref(string s, vector<long long> &hashPref)
{
	long long n = s.size();
	hashPref.resize(n + 1);
	for (long long i = 0; i < n; ++i)
		hashPref[i + 1] = ((hashPref[i] * b % p) + (s[i] - 'a' + 1)) % p;
}

long long HashSegment(vector<long long> &hashPref, long long l, long long r)
{
	return (hashPref[r + 1] - ((hashPref[l] * bpow[r - l + 1]) % p) + p) % p;
}

bool less(string s1, string s2, vector<long long> h1, vector<long long> h2)
{
	int l = 0, r = min(s1.size(), s2.size()) + 1;
	while (l + 1 < r)
	{
		int m = (l + r) / 2;
		if (h1[m] == h2[m])
			l = m;
		else
			r = m;
	}
	return s1[l - 1] < s2[l - 1];
}

int main()
{
	InitBpow();
	long long n;
	cin >> n;
	vector<string> s(n);
	vector<vector<long long>> h(n);
	long long minl = 100000;
	for (int i = 0; i < n; ++i)
	{
		cin >> s[i];
		minl = min(minl, (long long)s[i].size());
		InintHashPref(s[i], h[i]);
	}
	int l = 0, r = minl + 1;
	pair<long long, long long> ans = { 0, 0 };
	while (l + 1 < r)
	{
		long long m = (l + r) / 2;
		map<long long, pair<long long, long long>> seg, nseg;
		for (int i = 0; i < s[0].size() - m + 1; ++i)
			seg[HashSegment(h[0], i, i + m - 1)] = {0, i};
		for (int i = 1; i < s.size(); ++i)
		{
			for (int j = 0; j < s[i].size() - m + 1; ++j)
				if (seg.find(HashSegment(h[i], j, j + m - 1)) != seg.end())
					nseg[HashSegment(h[i], j, j + m - 1)] = { i, j };
			seg = nseg;
			nseg.clear();
		}
		if (seg.size() > 0)
		{
			l = m;
			ans = seg.begin()->second;
		}
		else
			r = m;
	}
	for (int i = ans.second; i < ans.second + l; ++i)
		cout << s[ans.first][i];

	return 0;
}