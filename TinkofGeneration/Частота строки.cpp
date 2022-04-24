#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int INF = int(1e9);

int t = 43, p = int(1e9) + 7;

int n;
string s;

vector<int> powt, phash;
void build() {
    powt.resize(n + 1);
    powt[0] = 1;
    for (int i = 1; i <= n; ++i)
        powt[i] = (powt[i - 1] * 1ll * t) % p;
    phash.resize(n + 1);
    for (int i = 1; i <= n; ++i)
        phash[i] = (phash[i - 1] * 1ll * t + int(s[i - 1] - 'a') + 1) % p;
}

int hashlr(int l, int r) {
    return ((phash[r + 1] - phash[l] * 1ll * powt[r - l + 1]) % p + p) % p;
}

int hashh(string s) {
    int res = 0;
    for (auto& i : s)
        res = (res * 1ll * t + int(i - 'a') + 1) % p;
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> s;
    n = s.size();
    build();

    int q; cin >> q;
    vector<vector<int>> queryh(n + 1), queryk(n + 1), queryid(n + 1);
    vector<int> res(q, INF);

    vector<pair<int, pair<int, pair<int, int>>>> help228(q);
    for (int i = 0; i < q; ++i) {
        int k; string ss; cin >> k >> ss;
        help228[i] = { hashh(ss), {k, {i, ss.size()} } };
    }
    sort(help228.begin(), help228.end());
    for (auto& i : help228) {
        queryh[i.second.second.second].push_back(i.first);
        queryk[i.second.second.second].push_back(i.second.first);
        queryid[i.second.second.second].push_back(i.second.second.first);
    }

    for (int l = 1; l <= n; ++l) {
        int m = queryh[l].size();
        if (!m) continue;
        vector<vector<int>> h(m);
        for (int i = 0; i + l - 1 < n; ++i) {
            int hhhaaassshhh = hashlr(i, i + l - 1);
            int x = (lower_bound(queryh[l].begin(), queryh[l].end(), hhhaaassshhh)) - queryh[l].begin();
            if (x < m && queryh[l][x] == hhhaaassshhh)
                h[x].push_back(i);
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j + queryk[l][i] - 1 < h[i].size(); ++j)
                res[queryid[l][i]] = min(res[queryid[l][i]], h[i][j + queryk[l][i] - 1] - h[i][j] + l);
        }
    }
    for (auto& i : res)
        cout << (i < INF ? i : -1) << '\n';

    return 0;
}
