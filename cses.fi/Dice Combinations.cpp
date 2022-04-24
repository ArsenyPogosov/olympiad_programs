#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long p = 1e9 + 7;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	list<int> l;
	for (int i = 0; i < 5; ++i) l.push_back(0);
	l.push_back(1);
	for (int i = 0; i < n; ++i)
	{
		long long sum = 0;
		for (auto& i : l) sum += i;
		l.pop_front();
		l.push_back(sum % p);
	}
	cout << *prev(l.end()) << '\n';

	return 0;
}