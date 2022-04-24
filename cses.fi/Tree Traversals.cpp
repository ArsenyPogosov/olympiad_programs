#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
vector<int> a, b;

void pRiNt(int al, int ar, int bl, int br)
{
	if (al == ar) return;
	int pos = b[a[al]], lenl = pos - bl, lenr = br - pos - 1;
	pRiNt(al + 1, al + 1 + lenl, bl, bl + lenl);
	pRiNt(ar - lenr, ar, br - lenr, br);
	cout << a[al] + 1 << ' ';
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n; a.resize(n); b.resize(n);
	for (auto& i : a) cin >> i, --i;
	for (int i = 0; i < n; ++i)
	{
		int h; cin >> h;
		b[h - 1] = i;
	}
	pRiNt(0, n, 0, n);
	cout << '\n';

	return 0;
}