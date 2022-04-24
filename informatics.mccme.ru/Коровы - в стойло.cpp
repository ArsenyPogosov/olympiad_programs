#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int n, k;
	std::cin >> n >> k;
	std::vector<int> lenengradddd(n);
	for (auto& i : lenengradddd) std::cin >> i;
	std::sort(lenengradddd.begin(), lenengradddd.end());

	int l{ 1 }, r{ lenengradddd[n - 1] - lenengradddd[0] }, h, it;
	bool flag{ false };
	while (r - l > 1)
	{
		h = (r + l) / 2;
		it = 0;
		for (int i = 2; i <= k; ++i)
		{
			flag = false;
			for (int j = it + 1; j <= n-1; ++j)
				if ((lenengradddd[j] - lenengradddd[it]) >= h)
				{
					it = j;
					flag = true;
					break;
				}
			if (!flag) break;
		}
		if (flag)
			l = h;
		else
			r = h;
	}
	std::cout << l;

	return 0;
}
