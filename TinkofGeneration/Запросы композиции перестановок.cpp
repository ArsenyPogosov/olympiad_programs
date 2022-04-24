#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int n, m;
vector<vector<int>> a, da;

vector<int> Add(vector<int> &a, vector<int> &b) {
    vector<int> h(m);
    for (int i = 0; i < m; ++i)
        h[i] = b[a[i]];
    return h;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int t; cin >> t;
    while (t--) {
        cin >> n >> m;
        a.assign(n, vector<int>(m));
        for (auto& i : a)
            for (auto& j : i)
                cin >> j, --j;
        da.assign(n, vector<int>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                da[i][a[i][j]] = j;
        vector<vector<int>> pref(n + 1, vector<int>(m)), dpref(n + 1, vector<int>(m));
        iota(pref[0].begin(), pref[0].end(), 0);
        for (int i = 1; i <= n; ++i)
            pref[i] = Add(pref[i - 1], a[i - 1]);
        iota(dpref[0].begin(), dpref[0].end(), 0);
        for (int i = 1; i <= n; ++i)
            dpref[i] = Add(da[i - 1], dpref[i - 1]);
        int q; cin >> q;
        map<pair<int, int>, long long> ress;
        while (q--) {
            int l, r; cin >> l >> r;
            if (ress[{l, r}]) {
                cout << ress[{l, r}] << '\n';
                continue;
            }
            vector<int> hay = Add(dpref[l - 1], pref[r]);
            long long res = 0;
            for (int i = 0; i < m; ++i)
                res += (i + 1) * 1ll * (hay[i] + 1);
            cout << res << '\n';
            ress[{l, r}] = res;
        }
    }

    return 0;
}
