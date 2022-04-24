#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<int> N, M;
vector<vector<int>> t;
int cnt = 0;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, q; cin >> n >> m >> q;
	N.resize(n), M.resize(m);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
		{
			int h; cin >> h;
			N[i] = max(N[i], h);
			M[j] = max(M[j], h);
		}
	set<int> haveN, haveM;
	for (int i = 0; i < n; ++i) haveN.insert(N[i]);
	for (int j = 0; j < m; ++j) haveM.insert(M[j]);
	for (int j = 0; j < m; ++j)
			cnt += (haveN.find(M[j]) != haveN.end());
	while (q--)
	{
		int a, b, c; cin >> a >> b >> c; --a; --b;
		cnt -= (haveN.find(M[b]) != haveN.end());
		cnt -= (haveM.find(N[a]) != haveM.end());
		if (N[a] == M[b]) ++cnt;
		haveN.erase(haveN.find(N[a]));
		haveM.erase(haveM.find(M[b]));
		N[a] = max(N[a], c);
		M[b] = max(M[b], c);
		haveN.insert(N[a]);
		haveM.insert(M[b]);
		cnt += (haveN.find(M[b]) != haveN.end());
		cnt += (haveM.find(N[a]) != haveM.end());
		if (N[a] == M[b]) --cnt;
		cout << cnt << '\n';
	}

	return 0;
}