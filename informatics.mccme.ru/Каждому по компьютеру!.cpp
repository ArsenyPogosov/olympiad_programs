//source: https://informatics.msk.ru/mod/statements/view3.php?id=43886&chapterid=1137#1
//status: coding

#include <bits/stdc++.h>
using namespace std;
#define f_io
#pragma region switch_io
#ifdef f_io:
ifstream fin("input.txt");
ofstream fout("output.txt");
#define cin fin
#define cout fout
#endif
#pragma endregion

int main()
{
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> a(n), b(m);
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < m; ++i)
	{
		cin >> b[i].first;
		b[i].second = i + 1;
	}
	sort(b.begin(), b.end());

	vector<int> ans(n);
	int count = 0;
	for (int i = 0, it = 0; i < n && it < m; ++i)
	{
		while (it < m && a[i].first + 1 > b[it].first) ++it;
		if (it < m) { ans[a[i].second] = b[it++].second; ++count; }
	}
	cout << count << '\n';
	for (auto& i : ans)
		cout << i << ' ';

	return 0;
}