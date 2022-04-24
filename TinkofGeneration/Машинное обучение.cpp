#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int K = 3048;

int n;
vector<int> a;

vector<vector<int>> changeq;

const int mxl = 447;
bitset<mxl> cond;
vector<int> cnt;
vector<int> cnt1;

int t = 0, l = 0, r = 0;

void addel(int x) {
    x = cnt1[x]++;
    if (x < mxl && !--cnt[x])
        cond[x] = true;
    if (x + 1 < mxl && !cnt[x + 1]++)
        cond[x + 1] = false;
}

void delel(int x) {
    x = cnt1[x]--;
    if (x < mxl && !--cnt[x])
        cond[x] = true;
    if (x - 1 < mxl && !cnt[x - 1]++)
        cond[x - 1] = false;
}

void change(int i) {
    if (l <= changeq[i][0] && changeq[i][0] < r)
        delel(a[changeq[i][0]]);

    a[changeq[i][0]] = changeq[i][1];

    if (l <= changeq[i][0] && changeq[i][0] < r)
        addel(a[changeq[i][0]]);
}

void unchange(int i) {
    if (l <= changeq[i][0] && changeq[i][0] < r)
        delel(a[changeq[i][0]]);

    a[changeq[i][0]] = changeq[i][2];

    if (l <= changeq[i][0] && changeq[i][0] < r)
        addel(a[changeq[i][0]]);
}

void MoveTo(int L, int R, int T) {
    while (l > L)
        addel(a[--l]);
    while (r < R)
        addel(a[r++]);
    while (t < T)
        change(t++);

    while (l < L)
        delel(a[l++]);
    while (r > R)
        delel(a[--r]);
    while (t > T)
        unchange(--t);
}

short Res() {
    cond[0] = 0;
    return cond._Find_first();
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int tval = 1;
    unordered_map<int, int> shiza;

    int q; cin >> n >> q;
    a.resize(n);
    for (auto& i : a) {
        cin >> i;
        if (shiza.find(i) == shiza.end())
            shiza[i] = tval++;
        i = shiza[i];
    }
    cnt.resize(mxl);
    cnt1.resize(n + q + 10);
    cond.set();
    // cnt1.reserve(n + q);

    int tt = 0;
    vector<int> ha = a;
    vector<vector<int>> resq;
    while (q--)    {
        int h, b, c; cin >> h >> b >> c;
        if (h == 1)
            resq.push_back({ b - 1, c, tt });
        if (h == 2) {
            if (shiza.find(c) == shiza.end())
                shiza[c] = tval++;
            c = shiza[c];

            changeq.push_back({ b - 1, c, ha[b - 1] });
            ha[b - 1] = c;
            ++tt;
        }
    }

    int m = resq.size();
    vector<int> order(m);
    iota(order.begin(), order.end(), 0);
    sort(order.begin(), order.end(), [&](int a, int b) {
        return make_tuple(resq[a][0] / K, resq[a][1] / K * ((resq[a][0] / K) % 2 ? -1 : 1), resq[a][2]) <
               make_tuple(resq[b][0] / K, resq[b][1] / K * ((resq[a][0] / K) % 2 ? -1 : 1), resq[b][2]);
    });

    vector<short> res(m);
    for (auto& i : order) {
        MoveTo(resq[i][0], resq[i][1], resq[i][2]);
        res[i] = Res();
    }

    for (auto& i : res)
        cout << i << '\n';

    return 0;
}
