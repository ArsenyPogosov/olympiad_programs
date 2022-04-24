#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	bool good = false;
	while (n--)
	{
		int h; cin >> h;
		good |= h == 1;
	}
	cout << (good ? "Yes" : "No") << '\n';

	return 0;
}