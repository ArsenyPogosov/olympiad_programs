#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int mlog2(int n)
{
	int t = 0;
	while (((1 << (t+1)) - 1) < n) ++t;
	return t;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int d = mlog2(n);
		int pr = 1; n -= d + 1;
		cout << d << '\n';
		for (int i = d; i >= 1; --i)
		{
			int add = min(pr, n / i);
			n -= add * i;
			pr += add;
			cout << add << ' ';
		}
		cout << '\n';
	}

	return 0;
}