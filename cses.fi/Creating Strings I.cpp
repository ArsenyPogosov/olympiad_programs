#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	string s; cin >> s; sort(s.begin(), s.end());
	int count = 0;
	do
	{
		++count;
	} while (next_permutation(s.begin(), s.end()));
	cout << count << '\n';
	do
	{
		cout << s << '\n';
	} while (next_permutation(s.begin(), s.end()));

	return 0;
}