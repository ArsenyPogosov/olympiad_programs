#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	long long n, a; cin >> n >> a;
	long long res = 1;
	vector<pair<long long, int>> st{ {a, 0} };
	for (int i = 1; i < n; ++i)
	{
		a = (a * 214013 + 2531011) % (1ll << 32);
		while (st.size() && st.back().first < a)
			st.pop_back();
		if (st.size())
			res += i - st.back().second;
		else
			res += i + 1;
		res += st.size();
		st.emplace_back(a, i);
	}
	
	cout << res << '\n';

	return 0;
}