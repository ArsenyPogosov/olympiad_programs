#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<long long> tree;

void change(long long i, long long add)
{
	while (i < tree.size())
	{
		tree[i] += add;
		i = (i + 1) | i;
	}
}

long long sum(long long i)
{
	long long res = 0;
	while (i >= 0)
	{
		res += tree[i];
		i = ((i + 1) & i) - 1;
	}

	return res;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long n, l; cin >> n >> l;
	vector<long long> w(n);
	for (auto& i : w)
		cin >> i;

	vector<long long> ord(n);
	iota(ord.begin(), ord.end(), 0);
	stable_sort(ord.begin(), ord.end(), [&](long long a, long long b){
		return (a + l * w[a] < b + l * w[b]);
	});

	long long res = 0;
	tree.resize(n);
	for (long long i = 0; i < n; ++i)
	{
		res += i - sum(ord[i]);
		change(ord[i], 1);
	}

	cout << res << '\n';

	return 0;
}