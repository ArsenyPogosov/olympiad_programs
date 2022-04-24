#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

// ------------------------PSTACK-----------------------------

struct pstacknode {
    int top, size;
    pstacknode *prev;
    pstacknode() : top(-1), size(0), prev(nullptr) { }
    pstacknode(int x): top(x), size(1), prev(nullptr) { }
};
typedef pstacknode* pstack;

int size(pstack t) {
    if (!t) return 0;
    return t->size;
}

pstack push(pstack t, int x) {
    pstacknode* res = new pstacknode(x);
    res->prev = t;
    res->size = size(t) + 1;

    return res;
}

int top(pstack t) {
    if (!t) return 0;
    return t->top;
}

pstack pop(pstack t) {
    if (!t) return nullptr;
    return t->prev;
}

// -------------------------PQUEUE--------------------------------

struct pqueue {
    bool recopy, copied;
    int tocopy;
    pstack l, ln, r, rn, s;
    pqueue() {
        l = ln = r = rn = s = nullptr;
        recopy = copied = false;
        tocopy = 0;
    }
    pqueue(pstack l, pstack ln, pstack r, pstack rn, pstack s, bool recopy, bool copied, int tocopy):
        l(l), ln(ln), r(r), rn(rn), s(s), recopy(recopy), copied(copied), tocopy(tocopy) { }
};

void work(pqueue& q) {
    if (!q.recopy) {
        q.recopy = size(q.l) > size(q.r);
        if (q.recopy) {
            q.tocopy = size(q.r);
            q.copied = (q.tocopy == 0);
            q.rn = q.r;
        }
    }
    if (q.recopy) {
        int todo = 3;
        while (todo > 0 && !q.copied) {
            int x = top(q.r); q.r = pop(q.r);
            q.s = push(q.s, x);
            if (!size(q.r))
                q.copied = true;
            --todo;
        }
        while (todo > 0 && size(q.l) > 0) {
            int x = top(q.l); q.l = pop(q.l);
            q.r = push(q.r, x);
            --todo;
        }
        while (todo > 0 && size(q.s) > 0) {
            int x = top(q.s); q.s = pop(q.s);
            if (q.tocopy > 0) {
                q.r = push(q.r, x);
                --q.tocopy;
            }
            --todo;
        }
        q.recopy = size(q.s);
        if (!q.recopy)
            swap(q.l, q.ln);
    }
}

int top(pqueue q) {
    if (!q.recopy) return top(q.r);
    if (q.tocopy > 0) return top(q.rn);
    return top(q.r);
}

pqueue push(pqueue q, int x) {
    pqueue nq = q;
    if (!q.recopy)
        nq.l = push(nq.l, x);
    else
        nq.ln = push(nq.ln, x);

    work(nq);
    return nq;
}

pqueue pop(pqueue q) {
    pqueue nq = q;
    if (!q.recopy) {
        nq.r = pop(nq.r);
    } else if (q.tocopy > 0) {
        nq.rn = pop(nq.rn);
        --nq.tocopy;
    } else {
        nq.r = pop(nq.r);
    }

    work(nq);
    return nq;
}

// --------------------------END----------------------------

int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector<pqueue> root{ pqueue() };
    int n; cin >> n;
    while (n--) {
        int h, t;
        cin >> h >> t;
        if (h == 1)    {
            int m; cin >> m;
            root.push_back(push(root[t], m));
        }
        if (h == -1) {
            cout << top(root[t]) << '\n';
            root.push_back(pop(root[t]));
        }
    }

    return 0;
}
