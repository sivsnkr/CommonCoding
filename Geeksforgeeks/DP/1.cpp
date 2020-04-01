#include<bits/stdc++.h>
using namespace std;

bool getres(int arr[], int n, int sum)
{
	int subset[sum+1][n+1];

	// if sum 0, then true
	int i;
	for(i = 0; i < n; i++)
	{
		subset[0][i] = true;
	}

	// if subset 0, then false
	for(i = 0; i < n; i++)
	{
		subset[i][0] = false;
	}

	for(i = 1; i <= n; i++)
	{
		for(int j = 1; j <= sum; j++)
		{
			if(j < arr[i-1])
				subset[j][i] = subset[j][i-1];
			else
				subset[j][i] = subset[j][i-1] || subset[j-arr[i-1]][i-1];
		}
	}

	return subset[sum][n];
}

// main driver code
int main()
{
	int set[] = {3, 34, 4, 12, 5, 2}; 
  	int sum = 2;
	bool res = getres(set,6,sum);
	res?cout<<"True":cout<<"False";
	cout<<endl;
}