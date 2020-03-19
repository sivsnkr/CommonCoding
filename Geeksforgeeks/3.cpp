#include <bits/stdc++.h>
using namespace std;

// void find_min(int dist[5][5], int &srci, int &srcj, bool visited[5][5])
// {
// 	int min = INT_MAX;
// 	int srcc = srci, srjc = srcj;
// 	if (srcc + 1 < 5)
// 	{
// 		if (dist[srcc + 1][srjc] < min && !visited[srcc + 1][srjc])
// 		{
// 			min = dist[srcc + 1][srjc];
// 			srci = srcc + 1;
// 		}
// 	}

// 	if (srcc - 1 >= 0)
// 	{
// 		if (dist[srcc - 1][srjc] < min && !visited[srcc - 1][srjc])
// 		{
// 			min = dist[srcc - 1][srjc];
// 			srci = srcc - 1;
// 		}
// 	}

// 	if (srjc + 1 < 5)
// 	{
// 		if (dist[srcc][srjc + 1] < min && !visited[srcc][srjc + 1])
// 		{
// 			min = dist[srcc][srjc + 1];
// 			srcj = srjc + 1;
// 			srci = srcc;
// 		}
// 	}

// 	if (srjc - 1 >= 0)
// 	{
// 		if (dist[srcc][srjc - 1] < min && !visited[srcc][srjc - 1])
// 		{
// 			min = dist[srcc][srjc - 1];
// 			srcj = srjc - 1;
// 			srci = srcc;
// 		}
// 	}
// }

void shortest_path(int grid[5][5], int row, int column)
{
	int dist[5][5];
	// memset(dist,500,sizeof(int)*row*column);

	int i, j;

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			dist[i][j] = 1000;
		}
	}

	dist[0][0] = 0;

	int srci = 0, srcj = 0;
	bool visited[5][5] = {0};

	priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < column; j++)
		{
			if (srci + 1 < 5)
			{
				if (dist[srci + 1][srcj] > dist[srci][srcj] + grid[srci + 1][srcj])
				{
					dist[srci + 1][srcj] = dist[srci][srcj] + grid[srci + 1][srcj];
				}
			}

			if (srci - 1 >= 0)
			{
				if (dist[srci - 1][srcj] > dist[srci][srcj] + grid[srci - 1][srcj])
				{
					dist[srci - 1][srcj] = dist[srci][srcj] + grid[srci - 1][srcj];
				}
			}

			if (srcj + 1 < 5)
			{
				if (dist[srci][srcj + 1] > dist[srci][srcj] + grid[srci][srcj + 1])
				{
					dist[srci][srcj + 1] = dist[srci][srcj] + grid[srci][srcj + 1];
				}
			}

			if (srcj - 1 >= 0)
			{
				if (dist[srci][srcj - 1] > dist[srci][srcj] + grid[srci][srcj - 1])
				{
					dist[srci][srcj - 1] = dist[srci][srcj] + grid[srci][srcj - 1];
				}
			}
		}
	}

	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			cout << dist[i][j] << "\t";
		}
		cout << endl;
	}
}

int main()
{
	int grid[5][5] =
		{
			31, 100, 65, 12, 18,
			10, 13, 47, 157, 6,
			100, 113, 174, 11, 33,
			88, 124, 41, 20, 140,
			99, 32, 111, 41, 20};

	shortest_path(grid, 5, 5);
}