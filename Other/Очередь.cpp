#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

deque<int> first, second;

void transmit(int d)
{
	while (d > 0)
	{
		second.push_front(first.back());
		first.pop_back();
		--d;
	}
	while (d < 0)
	{
		first.push_back(second.front());
		second.pop_front();
		++d;
	}
}

void relax()
{
	transmit((first.size() + second.size()) / 2 - second.size());
}

int pop()
{
	int res = first.front();
	first.pop_front();
	relax();
	return res;
}

void push_back(int x)
{
	second.push_back(x);
	relax();
}

void push_mid(int x)
{
	first.push_back(x);
	relax();
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int n; cin >> n;
	while (n--)
	{
		char h; cin >> h;
		if (h == '+')
		{
			int i; cin >> i;
			push_back(i);
		}
		if (h == '*')
		{
			int i; cin >> i;
			push_mid(i);
		}
		if (h == '-')
		{
			cout << pop() << '\n';
		}
	}

	return 0;
}