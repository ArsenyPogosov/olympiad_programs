#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int K = 1024 + 200, K2 = 500 - 50;

int n;
vector<int> a;

vector<int> resss;
vector<int> bbblock;

void ChangeB(int v1, int v2) {
    if (v1 + 1 <= v2) {
        int l = v1 + 1, r = v2;
        int h;
        h = (-l % K2);
        if (h < 0) h += K2;
        for (; h-- && l <= r; ++l)
            --resss[l];
        for (int i = l / K2; l + K2 < r; l += K2, ++i)
            --bbblock[i];
        for (; l <= r; ++l)
            --resss[l];
    }
    if (v2 + 1 <= v1) {
        int l = v2 + 1, r = v1;
        int h;
        h = (-l % K2);
        if (h < 0) h += K2;
        for (; h-- && l <= r; ++l)
            ++resss[l];
        for (int i = l / K2; l + K2 < r; l += K2, ++i)
            ++bbblock[i];
        for (; l <= r; ++l)
            ++resss[l];
    }
}

void Change(int i, int v) {
    ChangeB(a[i], v);
    a[i] = v;
}

int Res(int v) {
    return resss[v] + bbblock[v / K2];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n;
    a.resize(n);
    vector<vector<int>> vals;
    for (int i = 0; i < n; ++i) {
        vector<int> h(3);
        cin >> h[0];
        h[1] = 0;
        h[2] = i;
        vals.push_back(h);
    }

    int q; cin >> q;
    int m = 0;
    vector<vector<int>> query(q, vector<int>(4));
    for (int i = 0; i < q; ++i) {
        cin >> query[i][0];
        if (query[i][0] == 1) {
            cin >> query[i][1];
            --query[i][1];
            vector<int> h(3);
            cin >> h[0];
            h[1] = 1;
            h[2] = i;
            vals.push_back(h);
        }
        if (query[i][0] == 2) {
            ++m;
            vector<int> h(3);
            cin >> h[0];
            h[1] = 2;
            h[2] = i;
            vals.push_back(h);
            cin >> query[i][1] >> query[i][2];
            --query[i][1]; --query[i][2];
        }
    }

    sort(vals.begin(), vals.end(), [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; });
    int pre = -1e9, cnt = 0;
    for (auto& i : vals) {
        if (pre < i[0]) {
            pre = i[0];
            ++cnt;
        }
        if (i[1] == 0)
            a[i[2]] = cnt - 1;
        if (i[1] == 1)
            query[i[2]][2] = cnt - 1;
        if (i[1] == 2)
            query[i[2]][3] = cnt - 1;
    }
    vector<int> qres(m);

    resss.resize(cnt);
    for (int i = 0; i * K < n; ++i) {
        int l = i * K, r = min(n, l + K) - 1;
        bbblock.assign(cnt / K2 + 1, 0);
        vector<int> srt(r - l + 1);
        copy(a.begin() + l, a.begin() + r + 1, srt.begin());
        sort(srt.begin(), srt.end());
        int res = 0, pre = -1e9, from = 0;
        for (int j = 0; j < r - l + 1;) {
            pre = srt[j];
            for (; from <= pre; ++from) resss[from] = res;
            for (; j <= r && srt[j] == pre; ++j, ++res) {}
        }
        for (; from < cnt; ++from) resss[from] = res;

        int h = 0;
        for (auto& i : query) {
            if (i[0] == 1 && l <= i[1] && i[1] <= r)
                Change(i[1], i[2]);
            if (i[0] == 2) {
                if (i[1] <= l && r <= i[2]) {
                    qres[h] += r - l + 1 - 2 * Res(i[3]);
                } else {
                    for (int j = max(i[1], l); j <= min(i[2], r); ++j)
                        qres[h] += (a[j] < i[3] ? -1 : 1);
                }
                ++h;
            }
        }
    }
    for (auto& i : qres)
        cout << max(i, 0) << '\n';

    return 0;
}
