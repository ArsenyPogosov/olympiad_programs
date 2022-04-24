#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	vector<int> x(n);
	for (auto& i : x) cin >> i;
	stack<int> s;
	for (int i = 0; i < n; ++i)
	{
		while (s.size() && x[s.top()] >= x[i]) s.pop();
		if (s.size())
			cout << s.top() + 1 << ' ';
		else
			cout << "0 ";
		s.push(i);
	}
	cout << '\n';

	return 0;
}