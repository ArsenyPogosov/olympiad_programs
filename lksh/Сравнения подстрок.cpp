#include <iostream>
#include <vector>
//#include <queue>
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

int main()
{
	InitBpow();
	string s;
	cin >> s;
	vector<long long> h;
	InintHashPref(s, h);
	long long m;
	cin >> m;
	for (long long i = 0; i < m; ++i)
	{
		long long l1, r1, l2, r2;
		cin >> l1 >> r1 >> l2 >> r2;
		if (HashSegment(h, l1 - 1, r1 - 1) == HashSegment(h, l2 - 1, r2 - 1))
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}