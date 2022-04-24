#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

int p = int(1e9) + 7;

vector<int> prime, minD, euler;

void erat(int n) {
    minD.resize(n); minD[0] = minD[1] = 1;
    euler.resize(n); euler[1] = 1;
    for (int i = 2; i < n; ++i) {
        if (!minD[i]) {
            minD[i] = i;
            prime.push_back(i);
            euler[i] = i - 1;
        }
        for (auto& j : prime) {
            if (j > minD[i] || i * j >= n) break;
            minD[i * j] = j;
            euler[i * j] = euler[i] * (j - (j < minD[i]));
        }
    }
}

vector<int> Dividers(int n) {
    vector<int> res{ 1 };
    while (n > 1) {
        int sz = res.size();
        int tek = minD[n], ptek = 1;
        while (minD[n] == tek) {
            n /= tek;
            ptek *= tek;
            for (int i = 0; i < sz; ++i)
                res.push_back(res[i] * ptek);
        }
    }

    return res;
}



int main() {
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    erat(int(1e6) + 10);
    vector<char> need(int(1e5) + 10);

    int n; cin >> n; ++n;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        for (auto& j : Dividers(a))
            need[j] = true;
    }

    long long res = 0;
    for (int i = 2; i < int(1e5) + 10; ++i)
        if (need[i])
            res += euler[i];
    cout << res << '\n';

    return 0;
}
