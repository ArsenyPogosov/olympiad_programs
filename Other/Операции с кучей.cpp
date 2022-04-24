#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

template <typename T>
class heap
{
public:
	void insert(int x)
	{
		data.push_back(x);
		siefup(size() - 1);
	}

	void pop_front()
	{
		data.front() = data.back();
		data.pop_back();
		if (size()) siefdown(0);
	}

	int front()
	{
		return data.front();
	}

	size_t size()
	{
		return data.size();
	}

private:
	vector<T> data;

	void siefup(int i)
	{
		while (i > 0 && data[(i - 1) / 2] > data[i])
		{
			swap(data[(i - 1) / 2], data[i]);
			i = (i - 1) / 2;
		}
	}

	void siefdown(int i)
	{
		while (true)
		{
			int j = -1;
			if (i < size() && ((j == -1) || (data[i] < data[j]))) j = i;
			if (i * 2 + 1 < size() && ((j == -1) || (data[i * 2 + 1] < data[j]))) j = i * 2 + 1;
			if (i * 2 + 2 < size() && ((j == -1) || (data[i * 2 + 2] < data[j]))) j = i * 2 + 2;

			if (i == j) break;
			swap(data[i], data[j]);
			swap(i, j);
		}
	}
};

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int cnt = 0;
	ostringstream out;

	heap<int> hp;

	int m; cin >> m;
	while (m--)
	{
		string s; cin >> s;
		if (s == "insert")
		{
			int x; cin >> x;

			hp.insert(x);

			++cnt;
			out << s << ' ' << x << '\n';
		}
		if (s == "getMin")
		{
			int x; cin >> x;

			while (hp.size() && hp.front() < x)
			{
				++cnt;
				out << "removeMin\n";
				hp.pop_front();
			}

			if (!hp.size() || hp.front() > x)
			{
				++cnt;
				out << "insert " << x << '\n';
				hp.insert(x);
			}

			++cnt;
			out << s << ' ' << x << '\n';
		}
		if (s == "removeMin")
		{
			if (!hp.size())
			{
				++cnt;
				out << "insert " << 228 << '\n';
			}
			else
				hp.pop_front();

			++cnt;
			out << s << '\n';
		}
	}

	cout << cnt << '\n' << out.str();

	return 0;
}