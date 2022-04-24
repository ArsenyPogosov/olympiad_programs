#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

vector<int> prime, mind, phi;

void cieve(int n)
{
	mind.resize(n + 1); phi.resize(n + 1);
	phi[0] = 0; phi[1] = 1;
	for (int i = 2; i <= n; ++i)
	{
		if (!mind[i])
		{
			prime.push_back(i);
			mind[i] = i;
			phi[i] = i - 1;
		}
		for (auto& p : prime)
		{
			if (p * i > n) break;
			mind[p * i] = p;
			if (p == mind[i])
			{
				phi[p * i] = p * phi[i];
				break;
			}
			phi[p * i] = (p - 1) * phi[i];
		}
	}
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	cieve(n);
	long long res = -1;
	for (auto& i : phi)
		res += i * 2;
	cout << res << '\n';

	return 0;
}