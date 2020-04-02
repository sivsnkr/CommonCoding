#include<bits/stdc++.h>
using namespace std;

bool getres(int arr[], int n, int sum)
{
	int subset[sum+1][2];

	int i;
	for(i = 1; i <= sum; i++)
	{
		subset[i][0] = false;
	}

	for(i = 1; i <= n; i++)
	{
		for(int j = 0; j <= sum; j++)
		{
			if(j == 0)
				subset[j][i%2] = true;
			else if(j < arr[i-1])
				subset[j][i%2] = subset[j][(i+1)%2];
			else 
				subset[j][i%2] = subset[j][(i+1)%2]||subset[j-arr[i-1]][(i+1)%2];
		}
	}

	// cout<<"fsfsf"<<endl;
	return subset[sum][n%2];
}

// main driver code
int main()
{
	int set[] = {3, 34, 4, 12, 5, 2}; 
  	int sum = 7;
	bool res = getres(set,6,sum);
	res?cout<<"True":cout<<"False";
	cout<<endl;
}