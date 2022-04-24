#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const int p = 1e9 + 7;

int n, m;
vector<int> fenv;

void add(int i, int add)
{
	while (i < m)
	{
		fenv[i] += add;
		fenv[i] %= p;
		i = (i | (i + 1));
	}
}

int sum(int i)
{
	int res = 0;
	while (i >= 0)
	{
		res += fenv[i];
		res %= p;
		i = (i & (i + 1)) - 1;
	}
	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	vector<int> a(n);
	vector<pair<int, int>> ord(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> ord[i].first; ord[i].second = i;
	}
	sort(ord.begin(), ord.end());
	int prev = -1, count = -1;
	for (auto& i : ord)
	{
		if (prev < i.first)
		{
			prev = i.first;
			++count;
		}
		a[i.second] = count;
	}
	m = count + 1; fenv.resize(m); 
	for (auto& i : a)
		add(i, sum(i - 1) + 1);
	cout << sum(count) << '\n';

	return 0;
}