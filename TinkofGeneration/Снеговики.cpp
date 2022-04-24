#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

struct node {
    int sum, top;
    node *prev;
    node(int x = 0) : sum(x), top(x), prev(nullptr) { }
};
typedef node* stck;

vector<stck> root{ };

stck push(stck s, int m) {
    stck res = new node();
    res->top = m;
    res->sum = s->sum + m;
    res->prev = s;

    return res;
}

stck pop(stck s) {
    stck res = new node();
    *res = *s->prev;

    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n; cin >> n;
    root.push_back(new node());

    for (int i = 0; i < n; ++i)    {
        int t, m; cin >> t >> m;
        if (m)
            root.push_back(push(root[t], m));
        else
            root.push_back(pop(root[t]));
    }

    long long res = 0;
    for (auto& i : root)
        res += i->sum;

    cout << res << '\n';

    return 0;
}
