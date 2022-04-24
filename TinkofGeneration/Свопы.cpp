#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
vector<int> a;

vector<int> res(int i)
{
	if (i * 2 + 1 >= n) 
		return { a[i] };
	if (i * 2 + 2 >= n)
		return { min(a[i], a[i * 2 + 1]), max(a[i], a[i * 2 + 1]) };

	vector<int> res1, res2;
	if (a[i] < a[i * 2 + 1] && a[i] < a[i * 2 + 2])
	{
		res1.push_back(a[i]);
		vector<int> rl = res(i * 2 + 1);
		vector<int> rr = res(i * 2 + 2);
		for (int l = 1; l - 1 < max(rl.size(), rr.size()); l <<= 1)
		{
			for (int j = l - 1; j < l * 2 - 1 && j < rl.size(); ++j)
				res1.push_back(rl[j]);
			for (int j = l - 1; j < l * 2 - 1 && j < rr.size(); ++j)
				res1.push_back(rr[j]);
		}

		return res1;
	}
	if (a[i * 2 + 1] < a[i] && a[i * 2 + 1] < a[i * 2 + 2])
	{
		swap(a[i], a[i * 2 + 1]);

		res1.push_back(a[i]);
		vector<int> rl = res(i * 2 + 1);
		vector<int> rr = res(i * 2 + 2);
		for (int l = 1; l - 1 < max(rl.size(), rr.size()); l <<= 1)
		{
			for (int j = l - 1; j < l * 2 - 1 && j < rl.size(); ++j)
				res1.push_back(rl[j]);
			for (int j = l - 1; j < l * 2 - 1 && j < rr.size(); ++j)
				res1.push_back(rr[j]);
		}

		swap(a[i], a[i * 2 + 1]);
		return res1;
	}
	if (a[i * 2 + 2] < a[i] && a[i * 2 + 2] < a[i * 2 + 1])
	{
		swap(a[i], a[i * 2 + 2]);

		res1.push_back(a[i]);
		vector<int> rl = res(i * 2 + 1);
		vector<int> rr = res(i * 2 + 2);
		for (int l = 1; l - 1 < max(rl.size(), rr.size()); l <<= 1)
		{
			for (int j = l - 1; j < l * 2 - 1 && j < rl.size(); ++j)
				res1.push_back(rl[j]);
			for (int j = l - 1; j < l * 2 - 1 && j < rr.size(); ++j)
				res1.push_back(rr[j]);
		}

		swap(a[i], a[i * 2 + 2]);


		swap(a[i], a[i * 2 + 1]);
		swap(a[i], a[i * 2 + 2]);

		res2.push_back(a[i]);
		rl = res(i * 2 + 1);
		rr = res(i * 2 + 2);
		for (int l = 1; l - 1 < max(rl.size(), rr.size()); l <<= 1)
		{
			for (int j = l - 1; j < l * 2 - 1 && j < rl.size(); ++j)
				res2.push_back(rl[j]);
			for (int j = l - 1; j < l * 2 - 1 && j < rr.size(); ++j)
				res2.push_back(rr[j]);
		}

		swap(a[i], a[i * 2 + 2]);
		swap(a[i], a[i * 2 + 1]);

		return min(res1, res2);
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	cin >> n;
	a.resize(n);
	for (auto& i : a) cin >> i;

	for (auto& i : res(0)) cout << i << ' ';
	cout << '\n';

	return 0;
}