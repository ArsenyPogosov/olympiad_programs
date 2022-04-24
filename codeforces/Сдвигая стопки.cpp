#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long t; cin >> t;
	while (t--)
	{
		long long n; cin >> n;
		long long sum = 0;
		bool good = true;
		for (long long i = 0; i < n; ++i)
		{
			long long h; cin >> h;
			sum += h - i;
			if (sum < 0)
				good = false;
		}
		cout << (good ? "YES" : "NO") << '\n';
	}

	return 0;
}