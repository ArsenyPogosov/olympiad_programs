#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

long long res(long long a, long long b, long long c)
{
	return (a - b) * (a - b) + (b - c) * (b - c) + (c - a) * (c - a);
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t; cin >> t;
	while (t--)
	{
		int a, b, c; cin >> a >> b >> c;
		vector<int> A(a), B(b), C(c);
		for (auto& i : A) cin >> i;
		sort(A.begin(), A.end());
		for (auto& i : B) cin >> i;
		sort(B.begin(), B.end());
		for (auto& i : C) cin >> i;
		sort(C.begin(), C.end());
		long long mn = res(A[0], B[0], C[0]);
		for (auto& i : A)
		{
			int bit1 = (upper_bound(B.begin(), B.end(), i)) - B.begin() - 1;
			int cit1 = (lower_bound(C.begin(), C.end(), i)) - C.begin();
			if (bit1 >= 0 && cit1 < c)
				mn = min(mn, res(i, B[bit1], C[cit1]));
			int bit2 = (lower_bound(B.begin(), B.end(), i)) - B.begin();
			int cit2 = (upper_bound(C.begin(), C.end(), i)) - C.begin() - 1;
			if (bit2 < b && cit2 >= 0)
				mn = min(mn, res(i, B[bit2], C[cit2]));
		}
		for (auto& i : B)
		{
			int bit1 = (upper_bound(A.begin(), A.end(), i)) - A.begin() - 1;
			int cit1 = (lower_bound(C.begin(), C.end(), i)) - C.begin();
			if (bit1 >= 0 && cit1 < c)
				mn = min(mn, res(i, A[bit1], C[cit1]));
			int bit2 = (lower_bound(A.begin(), A.end(), i)) - A.begin();
			int cit2 = (upper_bound(C.begin(), C.end(), i)) - C.begin() - 1;
			if (bit2 < a && cit2 >= 0)
				mn = min(mn, res(i, A[bit2], C[cit2]));
		}
		for (auto& i : C)
		{
			int bit1 = (upper_bound(B.begin(), B.end(), i)) - B.begin() - 1;
			int cit1 = (lower_bound(A.begin(), A.end(), i)) - A.begin();
			if (bit1 >= 0 && cit1 < a)
				mn = min(mn, res(i, B[bit1], A[cit1]));
			int bit2 = (lower_bound(B.begin(), B.end(), i)) - B.begin();
			int cit2 = (upper_bound(A.begin(), A.end(), i)) - A.begin() - 1;
			if (bit2 < b && cit2 >= 0)
				mn = min(mn, res(i, B[bit2], A[cit2]));
		}
		cout << mn << '\n';
	}

	return 0;
}