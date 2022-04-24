#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

double distance(vector<long long>& a, vector<long long>& b)
{
	double res = 0;
	for (long long i = 0; i < a.size(); ++i)
		res += double(abs(a[i] - b[i]));

	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long q; cin >> q;
	while (q--)
	{
		long long h, w; cin >> h >> w;
		vector<vector<long long>> pic(h, vector<long long>(w));
		for (auto& i : pic)
			for (auto& j : i)
				cin >> j;

		if (distance(pic[h / 2 - 1], pic[h / 2]) < distance(pic[0], pic[h - 1]))
			cout << "NO\n";
		else
			cout << "YES\n";
	}

	return 0;
}