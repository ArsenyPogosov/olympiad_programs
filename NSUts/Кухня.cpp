#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a(228);
    vector<string> b(228);
    vector<int> x{ 26, 25, 23, 20, 16, 11 };
    //for (auto& i : x) i += 10;
    for (int i = 0; i < (1 << 6); ++i)
    {
        int count = 0, ii = i;
        string s = 'a';
        for (int t = 0; t < 6; ++t)
        {
            if (ii % 2 == 1)
                count += x[t];
            ii /= 2;
        }
        ++a[count];
        b[count] = i;
    }

    for (int i = 0; i < 228; ++i)
        if (a[i] > 1)
            cout << i << ' ' << b[i] << '\n';
    system("pause");
}
