#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int a, b, c, d, e; cin >> a >> b >> c >> d >> e;
	cout << min({ a, b / 2, c / 3, d / 3 ,e/ 3});

	return 0;
}