#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> del, p, used;
void DFS(int i, int p = -1, int c = 0)
{
	used[i] = true;
	if (c % 3 == 2) del[i] = true;
	int reg = 1;
	for (auto& j : graph[i])
		if (j != p && !used[j])
		{
			DFS(j, i, c + reg);
			reg = -reg;
		}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	srand(time(0) + 1327);
	int t; cin >> t;
	while (t--)
	{
		 cin >> n >> m;
		 vector<int> ord(n); 
		 iota(ord.begin(), ord.end(), 0);
		 random_shuffle(ord.begin(), ord.end());
		 graph.assign(n, {});
		 del.assign(n, false);
		 used.assign(n, 0);
		 p.assign(n, 0);
		 for (int i = 0; i < m; ++i)
		 {
			 int a, b; cin >> a >> b; --a; --b;
			 graph[ord[a]].push_back(ord[b]);
			 graph[ord[b]].push_back(ord[a]);
			 ++p[ord[a]]; ++p[ord[b]];
		 }
		 for (int i = 0; i < n; ++i)
			 if (p[i] > 2)
			 {
				 for (auto& j : graph[i])
					 if (!del[j])
						 --p[j];
				 del[i] = true;
			 }
		 for (int i = 0; i < n; ++i)
			 if (!used[i])
				 DFS(i);
		 int res = 0;
		 for (auto& i : del) if (i) ++res;
		 cout << res << '\n';
		 for (int i = 0; i < n; ++i)
			 if (del[ord[i]])
				 cout << i + 1 << ' ';
		 cout << '\n';
	}

	return 0;
}