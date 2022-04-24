#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;

int R(int k)
{
	return (n / k) + (n % k != 0) + k;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	int k = 1;
	for (int i = 2; i <= n; ++i)
		if (R(k) > R(i))
			k = i;
	vector<char> take(n), vkl(n);
	queue<int> free;
	for (int i = 0; i < n - 1; ++i)
		if ((i + 1) % k)
		{
			take[i] = true;
			free.push(i);
		}
	while (free.size() >= k)
	{
		cout << k << ' ';
		for (int i = 0; i < k; ++i)
		{
			int h = free.front(); free.pop();
			vkl[h] = true;
			cout << h + 1 << ' ';
		}
		cout << endl;
		int x; cin >> x; --x;
		for (int i = 0; i < k; ++i)
		{
			int tek = (x + i) % n;
			if (vkl[tek] && take[tek])
			{
				vkl[tek] = false;
				free.push(tek);
			}
		}
	}
	cout << 0 << endl;

	return 0;
}