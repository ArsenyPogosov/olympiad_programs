#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const int maxL = 14;

long long p, t;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	srand(time(0) + rand() + 228 + 1337);

	vector<char> alphabet;
	alphabet.push_back('_');
	for (char i = 'a'; i <= 'z'; ++i)
		alphabet.push_back(i);
	for (char i = 'A'; i <= 'Z'; ++i)
		alphabet.push_back(i);
	for (char i = '0'; i <= '9'; ++i)
		alphabet.push_back(i);

	string s; cin >> s;
	int n = s.size();
	cin >> p >> t;

	double abcdef = clock();

	vector<long long> tpow(maxL);
	tpow[0] = 1;
	for (int i = 1; i < maxL; ++i)
		tpow[i] = tpow[i - 1] * t % p;

	long long hash = 0;
	for (int i = 0; i < n; ++i)
		hash = (hash + s[i] * tpow[n - i - 1]) % p;

	while (true)
	{
		int l = rand() % 5 + maxL - 4;
		string curr = string(l, '@');
		for (auto&i: curr)
			i = alphabet[rand() % alphabet.size()];
		long long chash = 0;
		for (int i = 0; i < l; ++i)
			chash = (chash + curr[i] * tpow[l - i - 1]) % p;

		double start = clock();

		double t = 1;
		while (hash != chash || curr == s)
		{
			int i = rand() % l;
			char h = alphabet[rand() % alphabet.size()];

			if (abs(((chash - curr[i] * tpow[l - i - 1] + h * tpow[l - i - 1]) % p + p) % p - hash) < abs(chash - hash))
			{
				chash = ((chash - curr[i] * tpow[l - i - 1] + h * tpow[l - i - 1]) % p + p) % p;
				curr[i] = h;
			}
			else
				if (double(rand()) / RAND_MAX < t)
				{
					chash = ((chash - curr[i] * tpow[l - i - 1] + h * tpow[l - i - 1]) % p + p) % p;
					curr[i] = h;
				}

			t *= 0.05;

			if ((clock() - start) / CLOCKS_PER_SEC > 1)
				break;
		}
		if (hash == chash && curr != s)
		{
			cout << curr << '\n';
			break;
		}
	}

	cerr << (clock() - abcdef) / CLOCKS_PER_SEC << '\n';

	return 0;
}