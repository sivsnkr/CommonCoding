#include<bits/stdc++.h>
using namespace std;

bool isSafe(int matrix[4][5], int rowNum,int colNum, bool visited[4][5]){
	if(rowNum<4&&colNum<5&&!visited[rowNum][colNum]&&matrix[rowNum][colNum])
		return true;
	return false;
}

void dfs(int matrix[4][5], int i, int j, bool visited[4][5],int &count)
{
	visited[i][j] = true;

	int rowNum[8] = {-1,-1,-1,0,0,1,1,1};
	int colNum[8] = {-1,0,1,-1,1,-1,0,1};

	int k;

	for(k = 0; k < 8; k++)
	{
		if(isSafe(matrix,i+rowNum[k],j+colNum[k],visited))
		{
			count++;
			dfs(matrix,i+rowNum[k],j+colNum[k],visited,count);
		}
	}
}

int main()
{
	int matrix[4][5];

	int i,j;

	for(i = 0; i < 4; i++)
	{
		for(j = 0; j < 5; j++)
		{
			cin>>matrix[i][j];
		}
	}

	bool visited[4][5] = {0};

	int result = 0;

	for(i = 0; i < 4; i++)
	{
		for(j = 0;j < 5; j++)
		{
			if(!visited[i][j] && matrix[i][j])
			{
				int count = 1;
				dfs(matrix,i,j,visited,count);
				result = max(result,count);
			}
		}
	}

	cout<<result<<endl;
}
