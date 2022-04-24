#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long megaxor(long long x)
{
	long long res = 0;
	res = (x & 1 ? 0 : x);
	res = (res & (~1)) + ((x + 3) % 4 < 2);

	return res;
}

long long megaxor(long long a, long long b)
{
	return megaxor(b) ^ (a ? megaxor(a - 1) : 0);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long n; cin >> n;
	vector<pair<long long, long long>> bnim(n);

	long long res = 0;
	for (auto& i : bnim)
	{
		cin >> i.first >> i.second;
		res ^= megaxor(i.first, i.second);
	}

	if (!res)
	{
		cout << "Lose\n";
		return 0;
	}
	cout << "Win\n";

	for (auto& i : bnim)
	{
		long long a = i.first, b = i.second;
		if ((a ^ res) < a)
		{
			cout << a << ' ' << (a ^ res) <<  '\n';
			break;
		}

		long long h;
		for (long long j = 1; j <= res; j <<= 1)
			if (res & j)
				h = (a & (-j)) | j;

		if (h <= b)
		{
			cout << h << ' ' << (h ^ res) << '\n';
			break;
		}

	}

	return 0;
}