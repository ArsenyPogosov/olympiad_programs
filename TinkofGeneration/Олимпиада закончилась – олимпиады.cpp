#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	vector<int> x(n), y(n);
	vector<pair<int, int*>> srt(n * 2);
	for (int i = 0; i < n; ++i)
	{
		cin >> srt[i * 2 + 0].first >> srt[i * 2 + 1].first;
		srt[i * 2 + 0].second = &(x[i]);
		srt[i * 2 + 1].second = &(y[i]);
	}
	sort(srt.begin(), srt.end());
	int was = -1, t = 0;
	for (auto& i : srt)
	{
		if (was < i.first)
		{
			was = i.first;
			++t;
		}
		*i.second = t - 1;
	}

	vector<int> open(t), close(t), res(t);
	for (auto& i : x) ++open[i];
	for (auto& i : y) ++close[i];

	int cnt = 0;
	for (int i = 0; i < t; ++i)
	{
		res[i] = cnt;
		cnt -= close[i]; cnt += open[i];
		res[i] = cnt;
	}

	int q; cin >> q;
	while (q--)
	{
		int ind; cin >> ind; --ind;
		cout << *max_element(res.begin() + x[ind], res.begin() + y[ind]) << '\n';
	}

	return 0;
}