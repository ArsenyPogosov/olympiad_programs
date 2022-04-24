#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		long long x, y; cin >> x >> y;
		long long sqs = max(x, y) - 1, st = sqs*sqs + 1;
		if (sqs + 1 == x)
		{
			if (!(sqs % 2))
				cout << st + y - 1 << '\n';
			if (sqs % 2)
				cout << st - y + 1 + sqs + sqs << '\n';
			continue;
		}
		if (sqs + 1 == y)
		{
			if (!(sqs % 2))
				cout << st - x + 1 + sqs + sqs << '\n';
			if (sqs % 2)
				cout << st + x - 1 << '\n';
		}
	}

	return 0;
}