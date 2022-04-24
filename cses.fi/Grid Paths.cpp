#include <bits/stdc++.h>
#include <unordered_map>
#pragma GCC optimize("O2") 
using namespace std;

char s[48];
int was[7][7];
int ni = 0, nj = 0, its = 0;
char h = '@';
int ans = 0;
void res()
{
	if (its >= 48)
	{
		ans += ((ni == 6) && (nj == 0) && (!was[6][0]));
		return;
	}
	if (was[ni][nj]) return;
	if (h != '@')
	{
		if (h != 'D' && (ni == 0 || was[ni - 1][nj]) && (nj == 0 || !was[ni][nj - 1]) && (nj == 6 || !was[ni][nj + 1]))
			return;
		/*if (h != 'D' && ni != 0 && was[ni - 1][nj] && (nj == 0 || !was[ni - 1][nj - 1]) && (nj == 6 || !was[ni - 1][nj + 1]))
			return 0;*/
		if (h != 'U' && (ni == 6 || was[ni + 1][nj]) && (nj == 0 || !was[ni][nj - 1]) && (nj != 6 && !was[ni][nj + 1]))
			return;
		/*if (h != 'U' && ni != 6 && was[ni + 1][nj] && (nj == 0 || !was[ni + 1][nj - 1]) && (nj != 6 && !was[ni + 1][nj + 1]))
			return 0;*/
		if (h != 'L' && (nj == 6 || was[ni][nj + 1]) && (ni != 0 && !was[ni - 1][nj]) && (ni == 6 || !was[ni + 1][nj]))
			return;
		/*if (h != 'L' && nj != 6 && was[ni][nj + 1] && (ni != 0 && !was[ni - 1][nj + 1]) && (ni == 6 || !was[ni + 1][nj + 1]))
			return 0;*/
		if (h != 'R' && (nj == 0 || was[ni][nj - 1]) && (ni == 0 || !was[ni - 1][nj]) && (ni == 6 || !was[ni + 1][nj]))
			return;
		/*if (h != 'R' && nj != 0 || was[ni][nj - 1] && (ni == 0 || !was[ni - 1][nj - 1]) && (ni == 6 || !was[ni + 1][nj - 1]))
			return 0;*/
	}
	was[ni][nj] = true;
	if (was[6][0]) { was[ni][nj] = false; return; }
	if (s[its] == 'U' && ni > 0)
	{
		--ni;
		h = 'U';
		++its;
		res();
		--its;
		++ni;
	}
	if (s[its] == 'L' && nj > 0)
	{
		--nj;
		h = 'L';
		++its;
		res();
		--its;
		++nj;
	}
	if (s[its] == 'D' && ni < 6)
	{
		++ni;
		h = 'D';
		++its;
		res();
		--its;
		--ni;
	}
	if (s[its] == 'R' && nj < 6)
	{
		++nj;
		h = 'R';
		++its;
		res();
		--its;
		--nj;
	}
	if (s[its] == '?')
	{
		if (ni > 0)
		{
			--ni;
			h = 'U';
			++its;
			res();
			--its;
			++ni;
		}
		if (nj > 0)
		{
			--nj;
			h = 'L';
			++its;
			res();
			--its;
			++nj;
		}
		if (ni < 6)
		{
			++ni;
			h = 'D';
			++its;
			res();
			--its;
			--ni;
		}
		if (nj < 6)
		{
			++nj;
			h = 'R';
			++its;
			res();
			--its;
			--nj;
		}
	}
	was[ni][nj] = false;
}

int main()
{
	ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> s;
	int t = clock();
	//res();
	cout << ans << '\n';
	//cout << double(clock() - t)/CLOCKS_PER_SEC;

	return 0;
}