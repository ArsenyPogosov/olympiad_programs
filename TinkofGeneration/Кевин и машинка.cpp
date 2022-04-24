#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	string a, b; cin >> a >> b;

	int i = 0, j = 0, cnt = 0;
	for (; i < a.size() && j < b.size(); ++i)
	{
		cnt += a[i] - '0'; cnt %= 10;
		if (cnt == b[j] - '0')
		{
			cnt = 0;
			++j;
		}
	}

	if (j < b.size())
	{
		cout << "NO\n";
		return 0;
	}

	cnt = 0;
	for (; i < a.size(); ++i)
		cnt += a[i] - '0', cnt %= 10;

	if (cnt)
	{
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";

	return 0;
}