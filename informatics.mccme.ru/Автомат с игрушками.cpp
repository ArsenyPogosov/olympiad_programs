#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class cail {
public:
	int Al, Ar, Sl, Sr, Ap;

};

vector<int> Answ;
vector<cail> GameDesk;

int answer(int num)
{
	if (num == 0) return 1;

	if (GameDesk[GameDesk[num].Ap].Al == num)
	{
		if (GameDesk[GameDesk[num].Ap].Sl == 0) return -1;
		return Answ[GameDesk[num].Ap] + max(GameDesk[GameDesk[num].Ap].Sr - GameDesk[GameDesk[num].Ap].Sl, 0);
	}
	else
	{
		if (GameDesk[GameDesk[num].Ap].Sr == 0) return -1;
		return Answ[GameDesk[num].Ap] + max(GameDesk[GameDesk[num].Ap].Sl - GameDesk[GameDesk[num].Ap].Sr + 1, 0);
	}
}

int main()
{
	int n;
	cin >> n;
	GameDesk.resize(n);
	for (int i = 0; i <= n - 1; ++i)
	{
		cin >> GameDesk[i].Al >> GameDesk[i].Sl >> GameDesk[i].Ar >> GameDesk[i].Sr;
		GameDesk[i].Al = max(0, GameDesk[i].Al-1); GameDesk[i].Ar = max(0, GameDesk[i].Ar - 1);
		if (GameDesk[i].Al != 0) GameDesk[GameDesk[i].Al].Ap = i;
		if (GameDesk[i].Ar != 0) GameDesk[GameDesk[i].Ar].Ap = i;
	}
	int v;
	cin >> v;
	Answ.resize(n);
	for (int i = 0; i <= n - 1; ++i)
		Answ[i] = answer(i);
	cout << Answ[v - 1];
}