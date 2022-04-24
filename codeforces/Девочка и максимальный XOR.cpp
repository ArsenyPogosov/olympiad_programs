#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long bit(long long x, long long i)
{
	return (x & (1ll << i));
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long l, r; cin >> l >> r;
	int pos = 63;
	while (pos >= 0 && bit(l, pos) == bit(r, pos)) --pos;
	cout << (1ll << (pos + 1)) - 1 << '\n';

	return 0;
}