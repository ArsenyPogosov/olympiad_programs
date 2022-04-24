#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	string strocka;
	cin >> strocka;
	vector<vector<int>> answersLOLS(strocka.length(), vector<int>(strocka.length(), 1));
	vector<vector<string>> strtrtr(strocka.length(), vector<string>(strocka.length()));

	for (int i = 0; i <= strocka.length() - 1; ++i)
		for (int j = 0; j <= strocka.length() - 1 - i; ++j)
		{
			if ((strocka[j] == strocka[j + i]) && (i > 1))
			{
				answersLOLS[j][j + i] = answersLOLS[j + 1][j + i - 1] + 2;
				strtrtr[j][j + i] = strocka[j] + strtrtr[j + 1][j + i - 1] + strocka[j];
			}
			else
				if ((strocka[j] == strocka[j + i]) && (i == 1))
				{
					answersLOLS[j][j + i] = 2;
					strtrtr[j][j + i] = strocka[j]*2;
				}
				else
					if ((strocka[j] == strocka[j + i]) && (i == 0))
					{
						answersLOLS[j][j + i] = 1;
						strtrtr[j][j + i] = strocka[j];
					}
					else
					if (j != j + i)
					{
						if (answersLOLS[j][j + i - 1] > answersLOLS[j + 1][j + i])
						{
							answersLOLS[j][j + i] = answersLOLS[j][j + i - 1];
							strtrtr[j][j + i] = strtrtr[j][j + i - 1];
						}
						else
						{
							answersLOLS[j][j + i] = answersLOLS[j + 1][j + i];
							strtrtr[j][j + i] = strtrtr[j + 1][j + i];
						}
					}
		}
	cout << answersLOLS[0][strocka.length()-1] << '\n' << strtrtr[0][strocka.length() - 1];

	return 0;
}