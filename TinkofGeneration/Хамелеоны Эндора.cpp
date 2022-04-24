#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long n, k, l; cin >> n >> k >> l;
	vector<long long> coord(n), color(n);
	vector<char> dir(n);

	for (long long i = 0; i < n; ++i)
		cin >> coord[i] >> color[i] >> dir[i], dir[i] = (dir[i] == 'D');

	vector<double> res(k);
	long long sumr = 0, prev = 0, fl = 0;
	bool wf = false;
	vector<double> lenr(k);
	for (long long i = 0; i < n; ++i)
	{
		if (dir[i])
		{
			res[color[i]] += (l - coord[i]);
			sumr = (sumr - color[i] + k) % k;
			if (wf)
				lenr[(color[i] + sumr) % k] += coord[i] - prev;
			else
				fl = coord[i], wf = true;
			prev = coord[i];
		}
		else
		{
			double s = (coord[i] - prev) / 2.0;
			res[color[i]] += s;
			for (long long j = 0; j < k; ++j)
			{
				res[j] += lenr[(-color[i] + j + sumr + k) % k] / 2.0;
				s += lenr[(-color[i] + j + sumr + k) % k] / 2.0;
			}
			res[(color[i] - sumr + k) % k] += fl + s;
		}
	}

	for (auto& i : res)
		cout << i << ' ';
	cout << '\n';

	return 0;
}