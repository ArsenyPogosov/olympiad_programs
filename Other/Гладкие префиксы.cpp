#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> prime, d;

void sieve(long long n)
{
	d.resize(n + 1);

	d[0] = d[1] = 1;
	for (long long i = 2; i <= n; ++i)
	{
		if (!d[i]) d[i] = i, prime.push_back(i);
		for (auto& j : prime)
		{
			if (j > d[i] || j * i > n) break;
			d[j * i] = j;
		}
		d[i] = max(d[i], d[i / d[i]]);
	}
}

bool good(long long n, long long p)
{
	for (auto& i : prime)
	{
		if (i * i > n) break;
		while (n % i == 0) n /= i;
	}

	return (n <= p);
}

int customFunct(int param, int mod) {
	return ((param * param + 1) % mod);
}

int GCD(int x, int y)
{
	if (x == 0)
		return y;
	if (y == 0)
		return x;
	x = x % y;
	return GCD(y, x);
}

int PollardRho(int number) {
	int a = 2, b = 2, tmp;
	while (true)
	{
		a = customFunct(a, number);
		b = customFunct(customFunct(b, number), number);
		tmp = GCD(abs(b - a), number);
		if (tmp > 1)
			break;
	}
	return tmp;

}

bool good2(long long n)
{

}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long p; cin >> p;

	while (true)
	{
		long long x = PollardRho(p); p /= x;
		cout << p << ' ';
	}
	return 0;

	//sieve(p);

	int cnt = 0;
	vector<long long> now{ 0 };

	while (true)
	{
		cnt += now.size();
		vector<long long> nxt;
		for (auto& i : now)
			for (long long h = i * 10 + 1; h < i * 10 + 10; ++h)
				if (good(h, p))
					nxt.push_back(h);

		if (nxt.empty()) break;
		now = nxt;
	}

	cout << cnt << '\n';
	cout << *max_element(now.begin(), now.end()) << '\n';

	return 0;
}