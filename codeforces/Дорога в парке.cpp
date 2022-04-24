#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n, cnt = 0; cin >> n;
	while (true)
	{
		int a = rand() % n, b = rand() % n;
		cout << a << " + " << b << " == ";
		int h; cin >> h;
		if (h != a + b)
			break;
		++cnt;
	}
	cout << "!!!!!" << cnt << '\n';

	return 0;
}