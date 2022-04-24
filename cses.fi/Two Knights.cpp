#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n; cin >> n;
	for (long long i = 1; i <= n; ++i) 
		cout << (i * i) * (i * i - 1) / 2 - (i - 2) * (i - 1) * 4 << '\n';

	return 0;
}