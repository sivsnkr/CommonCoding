#include <bits/stdc++.h>
using namespace std;

void printres(int arr[4][4], int n)
{
	tuple<int, int, int> dp[n][n];
	dp[0][0] = {0, 0, 0};

	int i, j;
	int max_value = 0;
	pair<int, int> coordinates = {0, 0};
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i == 0 && j == 0)
				continue;
			if (i - 1 >= 0)
			{
				tuple<int, int, int> temp = {i, j, 0};
				if (arr[i - 1][j] == arr[i][j] - 1 || arr[i - 1][j] == arr[i][j] + 1)
				{
					// get the max pair value
					temp = {i - 1, j, get<2>(dp[i - 1][j]) + 1};
				}

				if (j - 1 >= 0)
				{
					if (get<2>(dp[i][j - 1]) + 1 > get<2>(temp))
					{
						temp = {i, j - 1, get<2>(dp[i][j - 1]) + 1};
					}
				}
				dp[i][j] = temp;
				if (get<2>(temp) > max_value)
				{
					max_value = get<2>(temp);
					coordinates = {i, j};
				}
			}
		}
	}
	cout << max_value << endl;

	i = coordinates.first, j = coordinates.second;
	while (1)
	{
		cout << arr[i][j] << " ";
		// break if movement no possible
		if (i == get<0>(dp[i][j]) && j == get<1>(dp[i][j]))
			break;

		i = get<0>(dp[i][j]), j = get<1>(dp[i][j]);
	}
	cout << endl;
}

int main()
{
	int n = 4;
	int mat[4][4] =
		{
			{9, 6, 5, 2},
			{8, 7, 6, 5},
			{7, 3, 1, 6},
			{1, 1, 1, 7},
		};

	printres(mat, n);
}