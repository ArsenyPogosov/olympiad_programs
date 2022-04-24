#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long powres(int pow)
{
	return (1ll << pow) / 2 * pow;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	long long n; cin >> n;
	long long res = 0;
	for (int i = 50; i >= 0; --i)
		if (n >= (1ll << i))
		{
			res += powres(i);
			n -= (1ll << i);
			res += n + 1;
		}
	cout << res << '\n';

	return 0;
}