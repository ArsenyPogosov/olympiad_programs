#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int N, n, m;
vector<int> s;

struct node {
    int x, y, cnt, sz;
    node* l, * r;

    node(int x = 0) : x(x), y(rand()* RAND_MAX + rand()), cnt(1), sz(1), l(nullptr), r(nullptr) {}
};
typedef node* tree;

int sz(tree t) {
    return (t ? t->sz : 0);
}

void fix(tree t) {
    if (!t) return;
    t->sz = sz(t->l) + t->cnt + sz(t->r);
}

void split(tree t, int val, tree& t1, tree& t2) {
    if (!t) {
        t1 = t2 = nullptr;
        return;
    }
    if (t->x < val)    {
        split(t->r, val, t->r, t2);
        fix(t);
        t1 = t;
        return;
    }
    if (t->x >= val) {
        split(t->l, val, t1, t->l);
        fix(t);
        t2 = t;
        return;
    }
}

tree merge(tree t1, tree t2) {
    if (!t1) return t2;
    if (!t2) return t1;

    if (t1->y < t2->y) {
        t1->r = merge(t1->r, t2);
        fix(t1);
        return t1;
    }
    if (t1->y >= t2->y)    {
        t2->l = merge(t1, t2->l);
        fix(t2);
        return t2;
    }
}

void add(tree& t, int val) {
    tree t1, t2, t2t3, t3;
    split(t, val, t1, t2t3);
    split(t2t3, val + 1, t2, t3);
    if (t2) {
        ++t2->cnt;
        ++t2->sz;
    } else {
        t2 = new node(val);
    }
    t = merge(merge(t1, t2), t3);
}

void del(tree& t, int val) {
    tree t1, t2, t2t3, t3;
    split(t, val, t1, t2t3);
    split(t2t3, val + 1, t2, t3);
    if (t2)    {
        --t2->cnt;
        --t2->sz;
        if (!t2->sz)
            t2 = nullptr;
    }
    t = merge(merge(t1, t2), t3);
}

int lcnt(tree& t, int val) {
    tree t1, t2;
    split(t, val, t1, t2);
    int res = sz(t1);
    t = merge(t1, t2);
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> m; N = n + m;
    s.resize(N);
    vector<int> h(n);
    for (auto& i : h) cin >> i;
    for (int i = 0; i < n; ++i)
        s[h[i] - 1] = i;
    for (int i = n; i < N; ++i)
        cin >> s[i];

    tree root = nullptr;
    vector<int> fq(n);
    for (int i = 0; i < n; ++i)    {
        fq[i] = lcnt(root, s[i]);
        add(root, s[i]);
    }

    int l = 0, r = 0;
    vector<int> z(N); z[0] = N;
    root = new node(s[0]);
    for (int i = 1; i < N; ++i)    {
        del(root, s[i - 1]);
        z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < N && z[i] < n) {
            if (fq[z[i]] != lcnt(root, s[i + z[i]])) break;
            add(root, s[i + z[i]]);
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }

    vector<int> res;
    for (int i = n; i < N; ++i)
        if (z[i] >= n)
            res.push_back(i);

    cout << res.size() << '\n';
    for (auto& i : res)
        cout << i - n + 1 << ' ';
    cout << '\n';

    return 0;
}
