#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

uint32_t x0, x1, a, b, c;

uint32_t next() {
    uint32_t t = x0 * a + x1 * b + c;
    x0 = x1;
    x1 = t;
    return x0 >> 2;
}

int imin = 0;
vector<uint32_t> mass;

void change(int i, int val)
{
    mass[i] = val;
    if (val < mass[imin])
        imin = i;
    else if (imin == i)
        imin = min_element(mass.begin(), mass.end()) - mass.begin();
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    int n, q;
    cin >> n >> q >> x0 >> x1 >> a >> b >> c;

    mass.resize(n, -1);

    uint32_t res = 0, t = 10099, p = t;
    while (q--)
    {
        uint32_t i = next();
        uint32_t x = next();
        change(i % n, x);
        res += mass[imin] * p;
        p *= t;
    }

    cout << res;

	return 0;
}