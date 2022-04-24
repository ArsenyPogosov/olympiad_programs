#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long p = 786433;
const long long maxn = 1ll << 18;
const long long wn = 5;
const long long wnneg = 471860;
const long long div2 = (p + 1) / 2;

vector<long long> wnpow(maxn), wnnegpow(maxn);

int rev(int x, int k)
{
	int res = 0;
	for (int i = 0; i < k; ++i)
		res |= ((x >> i) & 1) << (k - i - 1);
	return res;
}

void fft(vector<long long>& a, bool reg)
{
	int n = a.size(), k = 1;
	for (; !((n >> k) & 1); ++k);

	for (int i = 0; i < n; ++i)
	{
		int j = rev(i, k);
		if (i < j)
			swap(a[i], a[j]);
	}

	for (int l = 2; l <= n; l <<= 1)
		for (int i = 0; i < n; i += l)
			for (int j = 0; j < (l >> 1); ++j)
			{
				int x = i + j, y = i + j + (l >> 1);
				long long a0 = a[x], a1 = a[y], w;
				if (!reg)
					w = wnpow[j * (maxn / l)];
				if (reg)
					w = wnnegpow[j * (maxn / l)];
				a[x] = (a0 + w * a1) % p;
				a[y] = ((a0 - w * a1) % p + p) % p;
				if (reg)
				{
					a[x] = (a[x] * div2) % p;
					a[y] = (a[y] * div2) % p;
				}
			}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	wnpow[0] = 1;
	for (int i = 1; i < maxn; ++i) wnpow[i] = (wnpow[i - 1] * wn) % p;
	wnnegpow[0] = 1;
	for (int i = 1; i < maxn; ++i) wnnegpow[i] = (wnnegpow[i - 1] * wnneg) % p;

	int N, h; cin >> N >> h; ++h;
	int n = 1 << h;
	for (; n < N + 1; n <<= 1);
	vector<long long> r1(n), r2(n);
	r1[0] = 1;
	r2[0] = 0; r2[1] = 1;
	fft(r1, false);
	fft(r2, false);
	for (int i = 2; i <= h; ++i)
	{
		for (int j = 0; j < n; ++j)
			r1[j] = (r2[j] + r1[j] * 2) % p;
		//fft(r1, false);
		//fft(res, false);
		for (int j = 0; j < n; ++j)
		{
			int r2j = r2[j];
			r2[j] = (r2[j] * r1[j]) % p;
			r1[j] = r2j;
		}
		//fft(res, true);
		for (int j = 0; j < n; ++j)
			r2[j] = (r2[j] * wnpow[j * maxn / n]) % p;
		//r2[0] = 0;
		//for (int j = 0; j < n - 1; ++j)
		//	r2[j + 1] = res[j];
	}
	fft(r2, true);

	cout << r2[N] << '\n';

	return 0;
}