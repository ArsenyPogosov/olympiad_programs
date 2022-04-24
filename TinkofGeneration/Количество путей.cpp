#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n;
vector<vector<int>> graph;

vector<long long> res;

deque<int>* dfs(int v, int p = -1) {
    deque<int>* was = new deque<int>(1, 1);
    ++res[0];

    for (auto&i : graph[v])
        if (i != p) {
            deque<int>* now = dfs(i, v); now->push_front(0);
            if (now->size() > was->size()) swap(now, was);

            for (int a = 0; a < was->size(); ++a)
                for (int b = 0; b < now->size(); ++b)
                    res[a + b] += (*was)[a] * 1ll * (*now)[b];

            for (int b = 0; b < now->size(); ++b)
                (*was)[b] += (*now)[b];
        }

    return was;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;
    graph.resize(n);

    for (int i = 0; i < n - 1; ++i) {
        int a, b; cin >> a >> b; --a; --b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    res.resize(n);
    dfs(0);

    for (int i = 1; i < n; ++i)
        cout << res[i] << ' ';
    cout << '\n';

    return 0;
}
