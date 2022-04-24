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

vector<long long> bpow, bpowsort;

void InitBpow(long long n = 1000001)
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

bool equal(long long h1, long long h2)
{
	long long m = abs(h1 - h2);
	return binary_search(bpowsort.begin(), bpowsort.end(), m);
}

int main()
{
	InitBpow();
	bpowsort = bpow;
	sort(bpowsort.begin(), bpowsort.end());
	string a, b;
	cin >> a >> b;
	vector<long long> ha, hb;
	InintHashPref(a, ha);
	InintHashPref(b, hb);
	vector<long long> res;
	res.reserve(b.size());
	for (int i = 0; i < b.size() - a.size() + 1; ++i)
		if (equal(ha[a.size()], HashSegment(hb, i, i + a.size() - 1)))
			res.push_back(i + 1);
	cout << res.size() << '\n';
	for (auto&i : res)
		cout << i << ' ';

	return 0;
}