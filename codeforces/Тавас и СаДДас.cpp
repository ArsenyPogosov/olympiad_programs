#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	int res = 0, pow = 1;
	while (n)
	{
		res += (n % 10 == 7) * pow;
		pow = (pow << 1);
		n /= 10;
	}
	res += pow;
	cout << res - 1<< '\n';

	return 0;
}