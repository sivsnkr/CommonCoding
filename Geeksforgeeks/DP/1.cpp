#include<bits/stdc++.h>
using namespace std;

int getres(int matrix[3][3])
{
	int resmatrix[3][3];
	
	// populate all the rows first cell with cell value
	int i;
	for(i = 0; i < 3; i++)
	{
		resmatrix[i][0] = matrix[i][0];
	}

	// now assign optimall value to all the cell

	int j;
	for(j = 1; j < 3; j++)
	{
		for(i = 0; i < 3; i++)
		{
			int value = resmatrix[i][j-1];
			if(i > 0)
			{
				value = max(resmatrix[i-1][j-1],value);
			}

			if(i+1 < 3)
				value = max(value,resmatrix[i+1][j-1]);
			resmatrix[i][j] = matrix[i][j]+value;//max value it can get
		}
	}

	// get the max value from last column
	int returnvalue = 0;
	for(i = 0; i < 3; i++)
	{
		returnvalue = max(returnvalue,resmatrix[i][2]);
	}

	return returnvalue;
}

int main()
{
	// main driver code
	int gold[3][3]= {{1, 3, 14},
                   {2, 1, 4},
                  {0, 6, 4}};
	int res = getres(gold);
	cout<<res<<endl;
}