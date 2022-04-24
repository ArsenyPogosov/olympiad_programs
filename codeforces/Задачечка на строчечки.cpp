#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const int C = 'z' - 'a' + 1;

int t;
vector<vector<int>> nxt, tind;
vector<int> suf, tsuf;

void init() {
    t = 1; nxt.emplace_back(C, -1);
    tind.emplace_back(0);
    suf.push_back(0); tsuf.push_back(-1);
}

void add(string s, int ind) {
    int now = 0;
    for (auto& i : s) {
        if (nxt[now][i - 'a'] != -1) {
            now = nxt[now][i - 'a'];
        } else {
            nxt[now][i - 'a'] = t;
            now = t++;
            nxt.emplace_back(C, -1);
            tind.emplace_back(0);
            suf.push_back(-1); tsuf.push_back(-1);
        }
    }
    tind[now].push_back(ind);
}

void bfs() {
    queue<int> q; q.push(0);

    for (auto& i : nxt[0]) if (i == -1) i = 0;
    while (q.size()) {
        int v = q.front(); q.pop();

        for (int i = 0; i < C; ++i) {
            if (nxt[v][i] > 0) {
                suf[nxt[v][i]] = (v ? nxt[suf[v]][i] : 0);
                tsuf[nxt[v][i]] = (tind[suf[nxt[v][i]]].size() ? suf[nxt[v][i]] : tsuf[suf[nxt[v][i]]]);
                q.push(nxt[v][i]);
            } else {
                nxt[v][i] = nxt[suf[v]][i];
            }
        }
    }
}

int ind = 0;
vector<vector<int>> res;

int go(int v, char c) {
    int rs = nxt[v][c - 'a'], h = rs;
    for (; h != -1; h = tsuf[h])
        for (auto& i : tind[h])
            res[i].push_back(ind);
    ++ind;

    return rs;
}

int main() {
    //ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ifstream cin("inputik.txt");
    ofstream cout("outputik.txt");

    string s; cin >> s;
    int n; cin >> n;
    vector<int> len(n);
    res.resize(n);
    init();
    for (int i = 0; i < n; ++i)    {
        string h; cin >> h;
        len[i] = h.size();
        add(h, i);
    }
    bfs();

    int now = 0;
    for (auto& i : s)
        now = go(now, i);

    for (int i = 0; i < n; ++i)    {
        cout << res[i].size() << ' ';
        for (auto& j : res[i])
            cout << j - len[i] + 2 << ' ';
        cout << '\n';
    }

    return 0;
}
